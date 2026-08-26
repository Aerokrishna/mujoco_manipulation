// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/msg/detail/armos_joint_control__rosidl_typesupport_fastrtps_cpp.hpp"
#include "armos_interfaces/msg/detail/armos_joint_control__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace armos_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
cdr_serialize(
  const armos_interfaces::msg::ArmosJointControl & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;
  // Member: joint1
  cdr << ros_message.joint1;
  // Member: joint2
  cdr << ros_message.joint2;
  // Member: joint3
  cdr << ros_message.joint3;
  // Member: joint4
  cdr << ros_message.joint4;
  // Member: joint5
  cdr << ros_message.joint5;
  // Member: joint6
  cdr << ros_message.joint6;
  // Member: joint7
  cdr << ros_message.joint7;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  armos_interfaces::msg::ArmosJointControl & ros_message)
{
  // Member: mode
  cdr >> ros_message.mode;

  // Member: joint1
  cdr >> ros_message.joint1;

  // Member: joint2
  cdr >> ros_message.joint2;

  // Member: joint3
  cdr >> ros_message.joint3;

  // Member: joint4
  cdr >> ros_message.joint4;

  // Member: joint5
  cdr >> ros_message.joint5;

  // Member: joint6
  cdr >> ros_message.joint6;

  // Member: joint7
  cdr >> ros_message.joint7;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
get_serialized_size(
  const armos_interfaces::msg::ArmosJointControl & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mode
  {
    size_t item_size = sizeof(ros_message.mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint1
  {
    size_t item_size = sizeof(ros_message.joint1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint2
  {
    size_t item_size = sizeof(ros_message.joint2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint3
  {
    size_t item_size = sizeof(ros_message.joint3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint4
  {
    size_t item_size = sizeof(ros_message.joint4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint5
  {
    size_t item_size = sizeof(ros_message.joint5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint6
  {
    size_t item_size = sizeof(ros_message.joint6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: joint7
  {
    size_t item_size = sizeof(ros_message.joint7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
max_serialized_size_ArmosJointControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: mode
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: joint1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: joint7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = armos_interfaces::msg::ArmosJointControl;
    is_plain =
      (
      offsetof(DataType, joint7) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _ArmosJointControl__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const armos_interfaces::msg::ArmosJointControl *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArmosJointControl__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<armos_interfaces::msg::ArmosJointControl *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArmosJointControl__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const armos_interfaces::msg::ArmosJointControl *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArmosJointControl__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ArmosJointControl(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _ArmosJointControl__callbacks = {
  "armos_interfaces::msg",
  "ArmosJointControl",
  _ArmosJointControl__cdr_serialize,
  _ArmosJointControl__cdr_deserialize,
  _ArmosJointControl__get_serialized_size,
  _ArmosJointControl__max_serialized_size
};

static rosidl_message_type_support_t _ArmosJointControl__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArmosJointControl__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace armos_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_armos_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<armos_interfaces::msg::ArmosJointControl>()
{
  return &armos_interfaces::msg::typesupport_fastrtps_cpp::_ArmosJointControl__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armos_interfaces, msg, ArmosJointControl)() {
  return &armos_interfaces::msg::typesupport_fastrtps_cpp::_ArmosJointControl__handle;
}

#ifdef __cplusplus
}
#endif
