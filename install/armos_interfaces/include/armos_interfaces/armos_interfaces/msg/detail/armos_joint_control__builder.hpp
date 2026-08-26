// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__BUILDER_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armos_interfaces/msg/detail/armos_joint_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armos_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmosJointControl_joint7
{
public:
  explicit Init_ArmosJointControl_joint7(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  ::armos_interfaces::msg::ArmosJointControl joint7(::armos_interfaces::msg::ArmosJointControl::_joint7_type arg)
  {
    msg_.joint7 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint6
{
public:
  explicit Init_ArmosJointControl_joint6(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint7 joint6(::armos_interfaces::msg::ArmosJointControl::_joint6_type arg)
  {
    msg_.joint6 = std::move(arg);
    return Init_ArmosJointControl_joint7(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint5
{
public:
  explicit Init_ArmosJointControl_joint5(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint6 joint5(::armos_interfaces::msg::ArmosJointControl::_joint5_type arg)
  {
    msg_.joint5 = std::move(arg);
    return Init_ArmosJointControl_joint6(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint4
{
public:
  explicit Init_ArmosJointControl_joint4(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint5 joint4(::armos_interfaces::msg::ArmosJointControl::_joint4_type arg)
  {
    msg_.joint4 = std::move(arg);
    return Init_ArmosJointControl_joint5(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint3
{
public:
  explicit Init_ArmosJointControl_joint3(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint4 joint3(::armos_interfaces::msg::ArmosJointControl::_joint3_type arg)
  {
    msg_.joint3 = std::move(arg);
    return Init_ArmosJointControl_joint4(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint2
{
public:
  explicit Init_ArmosJointControl_joint2(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint3 joint2(::armos_interfaces::msg::ArmosJointControl::_joint2_type arg)
  {
    msg_.joint2 = std::move(arg);
    return Init_ArmosJointControl_joint3(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_joint1
{
public:
  explicit Init_ArmosJointControl_joint1(::armos_interfaces::msg::ArmosJointControl & msg)
  : msg_(msg)
  {}
  Init_ArmosJointControl_joint2 joint1(::armos_interfaces::msg::ArmosJointControl::_joint1_type arg)
  {
    msg_.joint1 = std::move(arg);
    return Init_ArmosJointControl_joint2(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

class Init_ArmosJointControl_mode
{
public:
  Init_ArmosJointControl_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmosJointControl_joint1 mode(::armos_interfaces::msg::ArmosJointControl::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_ArmosJointControl_joint1(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosJointControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::msg::ArmosJointControl>()
{
  return armos_interfaces::msg::builder::Init_ArmosJointControl_mode();
}

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__BUILDER_HPP_
