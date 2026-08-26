// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armos_interfaces:srv/ArmosSetMode.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__BUILDER_HPP_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armos_interfaces/srv/detail/armos_set_mode__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmosSetMode_Request_mode
{
public:
  explicit Init_ArmosSetMode_Request_mode(::armos_interfaces::srv::ArmosSetMode_Request & msg)
  : msg_(msg)
  {}
  ::armos_interfaces::srv::ArmosSetMode_Request mode(::armos_interfaces::srv::ArmosSetMode_Request::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetMode_Request msg_;
};

class Init_ArmosSetMode_Request_arm_id
{
public:
  Init_ArmosSetMode_Request_arm_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmosSetMode_Request_mode arm_id(::armos_interfaces::srv::ArmosSetMode_Request::_arm_id_type arg)
  {
    msg_.arm_id = std::move(arg);
    return Init_ArmosSetMode_Request_mode(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetMode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::srv::ArmosSetMode_Request>()
{
  return armos_interfaces::srv::builder::Init_ArmosSetMode_Request_arm_id();
}

}  // namespace armos_interfaces


namespace armos_interfaces
{

namespace srv
{

namespace builder
{

class Init_ArmosSetMode_Response_success
{
public:
  Init_ArmosSetMode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::armos_interfaces::srv::ArmosSetMode_Response success(::armos_interfaces::srv::ArmosSetMode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::srv::ArmosSetMode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::srv::ArmosSetMode_Response>()
{
  return armos_interfaces::srv::builder::Init_ArmosSetMode_Response_success();
}

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__BUILDER_HPP_
