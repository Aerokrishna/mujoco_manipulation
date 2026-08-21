"""
URDF to MJCF conversion for CyRo robot.

Generates CyRo.xml and meshes/ from a source URDF file.
"""

from __future__ import annotations

import os
import re
import shutil
import tempfile
import xml.etree.ElementTree as ET
from collections import defaultdict
from pathlib import Path

# joints to remove (rod joints in AG145)
DELETED_GRIPPER_JOINTS = {
    "left_robot_gripper_finger1_finger_joint",
    "left_robot_gripper_finger2_finger_joint",
    "right_robot_gripper_finger1_finger_joint",
    "right_robot_gripper_finger2_finger_joint",
}

# only these joints get actuators
GRIPPER_ACTUATED_JOINTS = {
    "left_robot_gripper_finger1_joint",
    "right_robot_gripper_finger1_joint",
}

# first body of each gripper; sites are inserted into its parent body
GRIPPER_FIRST_BODIES = [
    ("left_robot_gripper_base_link", ("ft_frame_left", "ee_frame_left")),
    ("right_robot_gripper_base_link", ("ft_frame_right", "ee_frame_right")),
    ("center_robot_clx_link", ("ee_frame_center",)),
]

def _indent(elem, level=0):
    i = "\n" + level * "    "
    if len(elem):
        if not elem.text or not elem.text.strip():
            elem.text = i + "    "
        for child in elem:
            _indent(child, level + 1)
        if not elem.tail or not elem.tail.strip():
            elem.tail = i
    else:
        if level and (not elem.tail or not elem.tail.strip()):
            elem.tail = i


def convert_urdf_to_xml(
    urdf_path: str | Path,
    output_dir: str | Path | None = None,
) -> None:
    """
    Convert CyRo URDF to MJCF XML and copy mesh files.

    Parameters
    ----------
    urdf_path : str | Path
        Path to CyRo.urdf (e.g. from robotic-setup-description).
    output_dir : str | Path, optional
        Directory for meshes/ and CyRo.xml. Defaults to package assets.
    """
    try:
        import trimesh
    except ImportError:
        raise ImportError(
            "trimesh required for URDF conversion. "
            "Install with: pip install trimesh"
        )
    import mujoco

    urdf_path = Path(urdf_path)
    if output_dir is None:
        output_dir = Path(__file__).parent / "assets"
    output_dir = Path(output_dir)
    meshes_root = output_dir / "meshes"

    tree = ET.parse(urdf_path)
    root = tree.getroot()
    print(f"Loaded URDF from {urdf_path}")

    # Remove collision sections
    for link in root.findall(".//link"):
        for collision in link.findall("collision"):
            link.remove(collision)

    mujoco_elem = ET.Element("mujoco")
    compiler_elem = ET.SubElement(mujoco_elem, "compiler")
    compiler_elem.set("discardvisual", "false")
    compiler_elem.set("fusestatic", "false")
    compiler_elem.set("strippath", "false")  # preserve mesh paths for resolution
    root.insert(0, mujoco_elem)

    # Fix zero inertia
    for inertia in root.findall(".//inertia"):
        for attr in ["ixx", "iyy", "izz"]:
            val = float(inertia.get(attr, 0.0))
            if val == 0.0:
                inertia.set(attr, "0.01")
        for attr in ["ixy", "ixz", "iyz"]:
            if inertia.get(attr) is None:
                inertia.set(attr, "0.0")
    print("URDF: Replaced zero diagonal inertia values with 0.01")

    stem_to_sources = defaultdict(set)
    for mesh in root.iter("mesh"):
        if "filename" in mesh.attrib:
            full_path = mesh.attrib["filename"].replace("file://", "")
            stem = Path(os.path.basename(full_path)).stem + ".stl"
            stem_to_sources[stem].add(full_path)
    duplicate_stems = {
        s for s, srcs in stem_to_sources.items() if len(srcs) > 1
    }
    print(f"Conflicting mesh names detected: {duplicate_stems}")

    urdf_parent = str(urdf_path.parent)

    for mesh in root.iter("mesh"):
        if "filename" not in mesh.attrib:
            continue
        full_path = mesh.attrib["filename"]
        file_name = os.path.basename(full_path)
        full_path_cleaned = full_path.replace("file://", "")

        match = re.search(
            r"(?:robotic-setup-description|robotic_system)/(.*?)/meshes/(.*?)/(?:visual|collision)",
            full_path_cleaned.replace("\\", "/"),
        )
        if match:
            relative_path = f"{match.group(1)}/{match.group(2)}"
        else:
            parts = Path(full_path_cleaned).parts
            if "meshes" in parts:
                idx = parts.index("meshes")
                relative_path = "/".join(parts[idx + 1 : -1])
            else:
                relative_path = "meshes"

        base_stem = Path(file_name).stem
        normalized_stem = base_stem + ".stl"
        if normalized_stem in duplicate_stems:
            path_prefix = relative_path.replace("/", "_")
            unique_stem = f"{path_prefix}_{base_stem}"
        else:
            unique_stem = base_stem

        unique_stl_name = unique_stem + ".stl"
        path_to_save = meshes_root / relative_path / unique_stl_name
        path_to_save.parent.mkdir(parents=True, exist_ok=True)

        if not path_to_save.is_file():
            if file_name.lower().endswith((".dae", ".obj")):
                mesh_obj = trimesh.load(full_path_cleaned)
                mesh_obj.export(str(path_to_save))
            elif file_name.lower().endswith(".stl"):
                shutil.copy(full_path_cleaned, path_to_save)

        mesh_path = (Path("meshes") / relative_path / unique_stl_name).as_posix()
        mesh.attrib["filename"] = mesh_path
    print("Mesh files (STL) added to meshes folder")

    # Write URDF to output_dir so MuJoCo finds meshes/ relative to it
    output_urdf = output_dir / f"{urdf_path.stem}_relative.urdf"
    tree.write(str(output_urdf), encoding="utf-8", xml_declaration=False)

    with tempfile.NamedTemporaryFile(
        suffix=".xml", delete=False
    ) as tmp:
        temp_xml = Path(tmp.name)
    try:
        model = mujoco.MjModel.from_xml_path(str(output_urdf))
        mujoco.mj_saveLastXML(str(temp_xml), model)

        tree = ET.parse(temp_xml)
        root = tree.getroot()

        for geom in root.findall(".//geom"):
            if (
                geom.get("contype") == "0"
                and geom.get("conaffinity") == "0"
                and geom.get("group") == "1"
                and geom.get("density") == "0"
            ):
                geom.set("contype", "1")
                geom.set("conaffinity", "1")
                if "group" in geom.attrib:
                    del geom.attrib["group"]
                if "density" in geom.attrib:
                    del geom.attrib["density"]
            
            # Get the parent body name to identify if this geom belongs to a tip link
            parent_body = None
            # Find the body tag that contains this geom
            for body in root.findall(".//body"):
                if geom in list(body):
                    parent_body = body.get("name", "")
                    break
            # Define the tip link names you want to target
            tip_links = [
                "right_robot_gripper_finger1_finger_tip_link",
                "right_robot_gripper_finger2_finger_tip_link",
                "left_robot_gripper_finger1_finger_tip_link",
                "left_robot_gripper_finger2_finger_tip_link"
            ]
            if parent_body in tip_links:
                geom.set("friction", "1 0.5 0.01")
                geom.set("solimp", "0.99 0.99 0.01")
                geom.set("solref", "0.01 1")

        print("XML file: collision enabled for all geoms")

        for mesh_elem in root.findall(".//mesh"):
            file_attr = mesh_elem.get("file")
            if not file_attr:
                continue
            found_path = None
            for dirpath, _, filenames in os.walk(meshes_root):
                for fname in filenames:
                    if fname.lower() == os.path.basename(file_attr).lower():
                        found_path = os.path.join(dirpath, fname)
                        break
                if found_path:
                    break
            if found_path:
                stl_path = Path(found_path).relative_to(output_dir)
                mesh_elem.set("file", str(stl_path).replace("\\", "/"))
            else:
                print(f"Mesh {file_attr} not found in {meshes_root}")

        option_node = ET.Element(
            "option",
            {
                "timestep": "0.001",
                "gravity": "0 0 -9.81",
                "integrator": "implicitfast",
                "noslip_iterations": "3",
                "cone": "elliptic",
                "impratio": "10",
            },
        )
        default_node = ET.Element("default")
        ET.SubElement(
            default_node,
            "joint",
            {"damping": "5.0", "armature": "0.05", "frictionloss": "0.001"},
        )
        ET.SubElement(
            default_node,
            "geom",
            {
                "condim": "4",
                "friction": "0.8 0.02 0.001",
                "solimp": "0.9 0.95 0.001",
                "solref": "0.02 1",
            },
        )
        ET.SubElement(
            default_node,
            "motor",
            {"ctrllimited": "true", "ctrlrange": "-300 300"},
        )
        ET.SubElement(
            default_node,
            "position",
            {
                "kp": "200",
                "kv": "40",
                "ctrllimited": "true",
                "ctrlrange": "-3.14 3.14",
            },
        )
        root.insert(1, default_node)
        # root.insert(1, option_node)

        actuator_root = root.find("actuator")
        if actuator_root is None:
            actuator_root = ET.SubElement(root, "actuator")
        for joint in root.findall(".//joint"):
            jname = joint.attrib.get("name")
            if jname:
                ET.SubElement(
                    actuator_root,
                    "position",
                    name=f"{jname}_motor",
                    joint=jname,
                    kp="200",
                )
        ET.SubElement(
            actuator_root,
            "position",
            {"name": "stereo_left_yaw_motor", "joint": "stereo_left_yaw", "kp": "200"},
        )
        ET.SubElement(
            actuator_root,
            "position",
            {
                "name": "stereo_right_yaw_motor",
                "joint": "stereo_right_yaw",
                "kp": "200",
            },
        )
        print("XML file: actuators added")

        parent_map = {child: parent for parent in root.iter() for child in parent}

        for gripper_first_body_name, sites in GRIPPER_FIRST_BODIES:
            gripper_body = root.find(f".//body[@name='{gripper_first_body_name}']")
            if gripper_body is None:
                continue
            target = parent_map.get(gripper_body)
            if target is not None:
                for site_name in reversed(sites):
                    site = ET.Element(
                        "site",
                        {
                            "name": site_name,
                            "pos": "0 0 0",
                            "size": "0.01 0.01 0.01",
                            "rgba": "1 0 0 1",
                            "type": "sphere",
                            "group": "1",
                        },
                    )
                    target.insert(0, site)

        target_body = root.find(".//body[@name='center_robot_clx_link']")
        if target_body is not None:
            for side, name, quat in [
                ("left", "stereo_left_mount", "0 0 0.707107 0.707107"),
                ("right", "stereo_right_mount", "0 0 0.707107 0.707107"),
            ]:
                body = ET.Element(
                    "body",
                    {"name": name, "pos": "0.05 0.0 0.0" if side == "left" else "-0.05 0.0 0.0"},
                )
                ET.SubElement(
                    body,
                    "joint",
                    {
                        "name": f"stereo_{side}_yaw",
                        "type": "hinge",
                        "axis": "0 0 1",
                        "range": "-3.1416 3.1416",
                    },
                )
                ET.SubElement(
                    body,
                    "geom",
                    {
                        "type": "capsule",
                        "fromto": "0 0 0 0 0 0.05",
                        "size": "0.01",
                        "rgba": "0.2 0.6 1 0.3",
                    },
                )
                cam_pos = "0 -0.05 0"
                ET.SubElement(
                    body,
                    "camera",
                    {
                        "name": f"stereo_{side}_cam",
                        "pos": cam_pos,
                        "quat": quat,
                        "fovy": "25",
                    },
                )
                target_body.append(body)

        sensor_elem = root.find("sensor")
        if sensor_elem is None:
            sensor_elem = ET.SubElement(root, "sensor")
        for sensor_type, sname, site in [
            ("force", "force_ee_right", "ft_frame_right"),
            ("torque", "torque_ee_right", "ft_frame_right"),
            ("force", "force_ee_left", "ft_frame_left"),
            ("torque", "torque_ee_left", "ft_frame_left"),
        ]:
            ET.SubElement(
                sensor_elem, sensor_type, {"name": sname, "site": site}
            )

        contact_elem = root.find("contact")
        if contact_elem is None:
            contact_elem = ET.SubElement(root, "contact")
        for b1, b2 in [
            ("left_robot_gripper_finger1_finger_link", "left_robot_gripper_finger1_finger_tip_link"),
            ("left_robot_gripper_finger2_finger_link", "left_robot_gripper_finger2_finger_tip_link"),
            ("right_robot_gripper_finger1_finger_link", "right_robot_gripper_finger1_finger_tip_link"),
            ("right_robot_gripper_finger2_finger_link", "right_robot_gripper_finger2_finger_tip_link"),
        ]:
            ET.SubElement(contact_elem, "exclude", {"body1": b1, "body2": b2})

        urdf_tree = ET.parse(urdf_path)
        equality_elem = root.find("equality")
        if equality_elem is None:
            equality_elem = ET.SubElement(root, "equality")
        for joint in urdf_tree.getroot().findall("joint"):
            mimic = joint.find("mimic")
            if mimic is not None:
                child_joint = joint.attrib["name"]
                target_joint = mimic.attrib.get("joint")
                multiplier = float(mimic.attrib.get("multiplier", "1.0"))
                offset = float(mimic.attrib.get("offset", "0.0"))
                ET.SubElement(
                    equality_elem,
                    "joint",
                    {
                        "joint1": target_joint,
                        "joint2": child_joint,
                        "polycoef": f"{offset} {multiplier} 0",
                    },
                )
        print("Added equality joints from mimic joints")

        # 1. Delete unwanted rod joints For DH AG 145 gripper
        for body in root.findall(".//body"):
            for joint in list(body.findall("joint")):
                jname = joint.attrib.get("name")
                if jname in DELETED_GRIPPER_JOINTS:
                    body.remove(joint)

        # 2. Process equality constraints
        equality_elem = root.find("equality")
        if equality_elem is not None:
            for eq in list(equality_elem.findall("joint")):
                j1 = eq.attrib.get("joint1")
                j2 = eq.attrib.get("joint2")
                # remove equality referencing deleted joints
                if j1 in DELETED_GRIPPER_JOINTS or j2 in DELETED_GRIPPER_JOINTS:
                    equality_elem.remove(eq)
                    continue

                # normalize polycoef values (1.xx -> 1.0)
                poly = eq.attrib.get("polycoef")
                if poly:
                    parts = poly.split()
                    if len(parts) >= 2:
                        coef = float(parts[1])
                        if abs(coef) >= 1.0:
                            coef = 1.0 if coef > 0 else -1.0
                        parts[1] = f"{coef:.1f}"
                        eq.set("polycoef", " ".join(parts))

        # 3. Remove unwanted gripper actuators
        actuator_elem = root.find("actuator")
        if actuator_elem is not None:
            for act in list(actuator_elem):
                joint_name = act.attrib.get("joint", "")
                # actuator controlling a gripper joint
                if "robot_gripper" in joint_name:
                    # keep only finger1 actuators
                    if joint_name not in GRIPPER_ACTUATED_JOINTS:
                        actuator_elem.remove(act)

        _indent(root)

        for body in root.iter("body"):
            if body.get("name") == "center_robot_link1" and body.get("pos") == "0 0 0.1555":
                body.set("pos", "0 0 0.157")
            if body.get("name") == "left_robot_link1" and body.get("pos") == "0 0 0.1":
                body.set("pos", "0 0 0.135")
            if body.get("name") == "right_robot_link1" and body.get("pos") == "0 0 0.1":
                body.set("pos", "0 0 0.135")

        output_xml = output_dir / f"{urdf_path.stem}.xml"
        tree.write(str(output_xml), encoding="utf-8", xml_declaration=False)
        print(f"XML saved to {output_xml}")
    finally:
        if temp_xml.exists():
            temp_xml.unlink()
        if output_urdf.exists():
            output_urdf.unlink()
            print("Deleted temporary CyRo_relative.urdf")
