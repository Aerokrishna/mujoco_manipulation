// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armos_interfaces:srv/ArmosSetGripper.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__BUILDER_HPP_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armos_interfaces/srv/detail/armos_set_gripper__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmosSetGripper_Request_position
{
public:
  Init_ArmosSetGripper_Request_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::armos_interfaces::srv::ArmosSetGripper_Request position(::armos_interfaces::srv::ArmosSetGripper_Request::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetGripper_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::srv::ArmosSetGripper_Request>()
{
  return armos_interfaces::srv::builder::Init_ArmosSetGripper_Request_position();
}

}  // namespace armos_interfaces


namespace armos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmosSetGripper_Response_message
{
public:
  explicit Init_ArmosSetGripper_Response_message(::armos_interfaces::srv::ArmosSetGripper_Response & msg)
  : msg_(msg)
  {}
  ::armos_interfaces::srv::ArmosSetGripper_Response message(::armos_interfaces::srv::ArmosSetGripper_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetGripper_Response msg_;
};

class Init_ArmosSetGripper_Response_success
{
public:
  Init_ArmosSetGripper_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmosSetGripper_Response_message success(::armos_interfaces::srv::ArmosSetGripper_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_ArmosSetGripper_Response_message(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetGripper_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::srv::ArmosSetGripper_Response>()
{
  return armos_interfaces::srv::builder::Init_ArmosSetGripper_Response_success();
}

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__BUILDER_HPP_
