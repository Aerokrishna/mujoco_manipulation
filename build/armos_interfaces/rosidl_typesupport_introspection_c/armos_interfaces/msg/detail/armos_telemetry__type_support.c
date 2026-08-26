// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "armos_interfaces/msg/detail/armos_telemetry__rosidl_typesupport_introspection_c.h"
#include "armos_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "armos_interfaces/msg/detail/armos_telemetry__functions.h"
#include "armos_interfaces/msg/detail/armos_telemetry__struct.h"


// Include directives for member types
// Member `joint_pos`
// Member `joint_vel`
// Member `joint_torque`
// Member `wrench`
// Member `tcp_pose`
// Member `tcp_twist`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  armos_interfaces__msg__ArmosTelemetry__init(message_memory);
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_fini_function(void * message_memory)
{
  armos_interfaces__msg__ArmosTelemetry__fini(message_memory);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_pos(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_pos(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_pos(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_pos(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_pos(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_pos(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_vel(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_vel(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_vel(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_vel(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_vel(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_vel(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_torque(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_torque(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_torque(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_torque(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_torque(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_torque(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_torque(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_torque(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__wrench(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__wrench(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__wrench(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__wrench(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__wrench(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__wrench(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__wrench(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__wrench(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__tcp_pose(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_pose(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_pose(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__tcp_pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_pose(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__tcp_pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_pose(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__tcp_pose(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__tcp_twist(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_twist(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_twist(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__tcp_twist(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_twist(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__tcp_twist(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_twist(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__tcp_twist(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_member_array[9] = {
  {
    "timestamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, timestamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "joint_pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, joint_pos),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_pos,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_pos,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_pos,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_pos,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_pos,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_pos  // resize(index) function pointer
  },
  {
    "joint_vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, joint_vel),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_vel,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_vel,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_vel,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_vel,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_vel,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_vel  // resize(index) function pointer
  },
  {
    "joint_torque",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, joint_torque),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__joint_torque,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__joint_torque,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__joint_torque,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__joint_torque,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__joint_torque,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__joint_torque  // resize(index) function pointer
  },
  {
    "wrench",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, wrench),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__wrench,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__wrench,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__wrench,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__wrench,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__wrench,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__wrench  // resize(index) function pointer
  },
  {
    "tcp_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, tcp_pose),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__tcp_pose,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_pose,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_pose,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__tcp_pose,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__tcp_pose,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__tcp_pose  // resize(index) function pointer
  },
  {
    "tcp_twist",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, tcp_twist),  // bytes offset in struct
    NULL,  // default value
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__size_function__ArmosTelemetry__tcp_twist,  // size() function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_const_function__ArmosTelemetry__tcp_twist,  // get_const(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__get_function__ArmosTelemetry__tcp_twist,  // get(index) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__fetch_function__ArmosTelemetry__tcp_twist,  // fetch(index, &value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__assign_function__ArmosTelemetry__tcp_twist,  // assign(index, value) function pointer
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__resize_function__ArmosTelemetry__tcp_twist  // resize(index) function pointer
  },
  {
    "manipulability",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, manipulability),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "singularity_distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces__msg__ArmosTelemetry, singularity_distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_members = {
  "armos_interfaces__msg",  // message namespace
  "ArmosTelemetry",  // message name
  9,  // number of fields
  sizeof(armos_interfaces__msg__ArmosTelemetry),
  armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_member_array,  // message members
  armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_init_function,  // function to initialize message memory (memory has to be allocated)
  armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_type_support_handle = {
  0,
  &armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_armos_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, armos_interfaces, msg, ArmosTelemetry)() {
  if (!armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_type_support_handle.typesupport_identifier) {
    armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &armos_interfaces__msg__ArmosTelemetry__rosidl_typesupport_introspection_c__ArmosTelemetry_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
