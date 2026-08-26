// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "armos_interfaces/msg/detail/armos_telemetry__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace armos_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ArmosTelemetry_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) armos_interfaces::msg::ArmosTelemetry(_init);
}

void ArmosTelemetry_fini_function(void * message_memory)
{
  auto typed_message = static_cast<armos_interfaces::msg::ArmosTelemetry *>(message_memory);
  typed_message->~ArmosTelemetry();
}

size_t size_function__ArmosTelemetry__joint_pos(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__joint_pos(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__joint_pos(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__joint_pos(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__joint_pos(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__joint_pos(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__joint_pos(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__joint_pos(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ArmosTelemetry__joint_vel(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__joint_vel(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__joint_vel(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__joint_vel(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__joint_vel(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__joint_vel(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__joint_vel(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__joint_vel(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ArmosTelemetry__joint_torque(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__joint_torque(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__joint_torque(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__joint_torque(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__joint_torque(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__joint_torque(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__joint_torque(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__joint_torque(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ArmosTelemetry__wrench(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__wrench(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__wrench(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__wrench(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__wrench(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__wrench(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__wrench(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__wrench(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ArmosTelemetry__tcp_pose(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__tcp_pose(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__tcp_pose(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__tcp_pose(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__tcp_pose(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__tcp_pose(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__tcp_pose(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__tcp_pose(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

size_t size_function__ArmosTelemetry__tcp_twist(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ArmosTelemetry__tcp_twist(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__ArmosTelemetry__tcp_twist(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void fetch_function__ArmosTelemetry__tcp_twist(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const float *>(
    get_const_function__ArmosTelemetry__tcp_twist(untyped_member, index));
  auto & value = *reinterpret_cast<float *>(untyped_value);
  value = item;
}

void assign_function__ArmosTelemetry__tcp_twist(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<float *>(
    get_function__ArmosTelemetry__tcp_twist(untyped_member, index));
  const auto & value = *reinterpret_cast<const float *>(untyped_value);
  item = value;
}

void resize_function__ArmosTelemetry__tcp_twist(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ArmosTelemetry_message_member_array[9] = {
  {
    "timestamp",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, timestamp),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "joint_pos",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, joint_pos),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__joint_pos,  // size() function pointer
    get_const_function__ArmosTelemetry__joint_pos,  // get_const(index) function pointer
    get_function__ArmosTelemetry__joint_pos,  // get(index) function pointer
    fetch_function__ArmosTelemetry__joint_pos,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__joint_pos,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__joint_pos  // resize(index) function pointer
  },
  {
    "joint_vel",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, joint_vel),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__joint_vel,  // size() function pointer
    get_const_function__ArmosTelemetry__joint_vel,  // get_const(index) function pointer
    get_function__ArmosTelemetry__joint_vel,  // get(index) function pointer
    fetch_function__ArmosTelemetry__joint_vel,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__joint_vel,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__joint_vel  // resize(index) function pointer
  },
  {
    "joint_torque",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, joint_torque),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__joint_torque,  // size() function pointer
    get_const_function__ArmosTelemetry__joint_torque,  // get_const(index) function pointer
    get_function__ArmosTelemetry__joint_torque,  // get(index) function pointer
    fetch_function__ArmosTelemetry__joint_torque,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__joint_torque,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__joint_torque  // resize(index) function pointer
  },
  {
    "wrench",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, wrench),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__wrench,  // size() function pointer
    get_const_function__ArmosTelemetry__wrench,  // get_const(index) function pointer
    get_function__ArmosTelemetry__wrench,  // get(index) function pointer
    fetch_function__ArmosTelemetry__wrench,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__wrench,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__wrench  // resize(index) function pointer
  },
  {
    "tcp_pose",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, tcp_pose),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__tcp_pose,  // size() function pointer
    get_const_function__ArmosTelemetry__tcp_pose,  // get_const(index) function pointer
    get_function__ArmosTelemetry__tcp_pose,  // get(index) function pointer
    fetch_function__ArmosTelemetry__tcp_pose,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__tcp_pose,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__tcp_pose  // resize(index) function pointer
  },
  {
    "tcp_twist",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, tcp_twist),  // bytes offset in struct
    nullptr,  // default value
    size_function__ArmosTelemetry__tcp_twist,  // size() function pointer
    get_const_function__ArmosTelemetry__tcp_twist,  // get_const(index) function pointer
    get_function__ArmosTelemetry__tcp_twist,  // get(index) function pointer
    fetch_function__ArmosTelemetry__tcp_twist,  // fetch(index, &value) function pointer
    assign_function__ArmosTelemetry__tcp_twist,  // assign(index, value) function pointer
    resize_function__ArmosTelemetry__tcp_twist  // resize(index) function pointer
  },
  {
    "manipulability",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, manipulability),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "singularity_distance",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(armos_interfaces::msg::ArmosTelemetry, singularity_distance),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ArmosTelemetry_message_members = {
  "armos_interfaces::msg",  // message namespace
  "ArmosTelemetry",  // message name
  9,  // number of fields
  sizeof(armos_interfaces::msg::ArmosTelemetry),
  ArmosTelemetry_message_member_array,  // message members
  ArmosTelemetry_init_function,  // function to initialize message memory (memory has to be allocated)
  ArmosTelemetry_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ArmosTelemetry_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ArmosTelemetry_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace armos_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<armos_interfaces::msg::ArmosTelemetry>()
{
  return &::armos_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmosTelemetry_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, armos_interfaces, msg, ArmosTelemetry)() {
  return &::armos_interfaces::msg::rosidl_typesupport_introspection_cpp::ArmosTelemetry_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
