# generated from rosidl_generator_py/resource/_idl.py.em
# with input from armos_interfaces:msg/ArmosTelemetry.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'joint_pos'
# Member 'joint_vel'
# Member 'joint_torque'
# Member 'wrench'
# Member 'tcp_pose'
# Member 'tcp_twist'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ArmosTelemetry(type):
    """Metaclass of message 'ArmosTelemetry'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('armos_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'armos_interfaces.msg.ArmosTelemetry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__armos_telemetry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__armos_telemetry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__armos_telemetry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__armos_telemetry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__armos_telemetry

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ArmosTelemetry(metaclass=Metaclass_ArmosTelemetry):
    """Message class 'ArmosTelemetry'."""

    __slots__ = [
        '_timestamp',
        '_joint_pos',
        '_joint_vel',
        '_joint_torque',
        '_wrench',
        '_tcp_pose',
        '_tcp_twist',
        '_manipulability',
        '_singularity_distance',
    ]

    _fields_and_field_types = {
        'timestamp': 'float',
        'joint_pos': 'sequence<float>',
        'joint_vel': 'sequence<float>',
        'joint_torque': 'sequence<float>',
        'wrench': 'sequence<float>',
        'tcp_pose': 'sequence<float>',
        'tcp_twist': 'sequence<float>',
        'manipulability': 'float',
        'singularity_distance': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp = kwargs.get('timestamp', float())
        self.joint_pos = array.array('f', kwargs.get('joint_pos', []))
        self.joint_vel = array.array('f', kwargs.get('joint_vel', []))
        self.joint_torque = array.array('f', kwargs.get('joint_torque', []))
        self.wrench = array.array('f', kwargs.get('wrench', []))
        self.tcp_pose = array.array('f', kwargs.get('tcp_pose', []))
        self.tcp_twist = array.array('f', kwargs.get('tcp_twist', []))
        self.manipulability = kwargs.get('manipulability', float())
        self.singularity_distance = kwargs.get('singularity_distance', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.joint_pos != other.joint_pos:
            return False
        if self.joint_vel != other.joint_vel:
            return False
        if self.joint_torque != other.joint_torque:
            return False
        if self.wrench != other.wrench:
            return False
        if self.tcp_pose != other.tcp_pose:
            return False
        if self.tcp_twist != other.tcp_twist:
            return False
        if self.manipulability != other.manipulability:
            return False
        if self.singularity_distance != other.singularity_distance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'timestamp' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'timestamp' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._timestamp = value

    @builtins.property
    def joint_pos(self):
        """Message field 'joint_pos'."""
        return self._joint_pos

    @joint_pos.setter
    def joint_pos(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_pos' array.array() must have the type code of 'f'"
            self._joint_pos = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_pos' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_pos = array.array('f', value)

    @builtins.property
    def joint_vel(self):
        """Message field 'joint_vel'."""
        return self._joint_vel

    @joint_vel.setter
    def joint_vel(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_vel' array.array() must have the type code of 'f'"
            self._joint_vel = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_vel' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_vel = array.array('f', value)

    @builtins.property
    def joint_torque(self):
        """Message field 'joint_torque'."""
        return self._joint_torque

    @joint_torque.setter
    def joint_torque(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'joint_torque' array.array() must have the type code of 'f'"
            self._joint_torque = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'joint_torque' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._joint_torque = array.array('f', value)

    @builtins.property
    def wrench(self):
        """Message field 'wrench'."""
        return self._wrench

    @wrench.setter
    def wrench(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'wrench' array.array() must have the type code of 'f'"
            self._wrench = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'wrench' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._wrench = array.array('f', value)

    @builtins.property
    def tcp_pose(self):
        """Message field 'tcp_pose'."""
        return self._tcp_pose

    @tcp_pose.setter
    def tcp_pose(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'tcp_pose' array.array() must have the type code of 'f'"
            self._tcp_pose = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'tcp_pose' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._tcp_pose = array.array('f', value)

    @builtins.property
    def tcp_twist(self):
        """Message field 'tcp_twist'."""
        return self._tcp_twist

    @tcp_twist.setter
    def tcp_twist(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'tcp_twist' array.array() must have the type code of 'f'"
            self._tcp_twist = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'tcp_twist' field must be a set or sequence and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._tcp_twist = array.array('f', value)

    @builtins.property
    def manipulability(self):
        """Message field 'manipulability'."""
        return self._manipulability

    @manipulability.setter
    def manipulability(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'manipulability' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'manipulability' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._manipulability = value

    @builtins.property
    def singularity_distance(self):
        """Message field 'singularity_distance'."""
        return self._singularity_distance

    @singularity_distance.setter
    def singularity_distance(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'singularity_distance' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'singularity_distance' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._singularity_distance = value
