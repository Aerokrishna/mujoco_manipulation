// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "armos_interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "armos_interfaces/msg/detail/armos_joint_control__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  armos_interfaces::msg::ArmosJointControl & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
get_serialized_size(
  const armos_interfaces::msg::ArmosJointControl & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
max_serialized_size_ArmosJointControl(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace armos_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_armos_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, armos_interfaces, msg, ArmosJointControl)();

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
