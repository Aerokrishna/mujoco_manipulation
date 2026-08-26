// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armos_interfaces:msg/ArmosCartControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__BUILDER_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armos_interfaces/msg/detail/armos_cart_control__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armos_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmosCartControl_c
{
public:
  explicit Init_ArmosCartControl_c(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  ::armos_interfaces::msg::ArmosCartControl c(::armos_interfaces::msg::ArmosCartControl::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_b
{
public:
  explicit Init_ArmosCartControl_b(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  Init_ArmosCartControl_c b(::armos_interfaces::msg::ArmosCartControl::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_ArmosCartControl_c(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_a
{
public:
  explicit Init_ArmosCartControl_a(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  Init_ArmosCartControl_b a(::armos_interfaces::msg::ArmosCartControl::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_ArmosCartControl_b(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_z
{
public:
  explicit Init_ArmosCartControl_z(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  Init_ArmosCartControl_a z(::armos_interfaces::msg::ArmosCartControl::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_ArmosCartControl_a(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_y
{
public:
  explicit Init_ArmosCartControl_y(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  Init_ArmosCartControl_z y(::armos_interfaces::msg::ArmosCartControl::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_ArmosCartControl_z(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_x
{
public:
  explicit Init_ArmosCartControl_x(::armos_interfaces::msg::ArmosCartControl & msg)
  : msg_(msg)
  {}
  Init_ArmosCartControl_y x(::armos_interfaces::msg::ArmosCartControl::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_ArmosCartControl_y(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

class Init_ArmosCartControl_mode
{
public:
  Init_ArmosCartControl_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmosCartControl_x mode(::armos_interfaces::msg::ArmosCartControl::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return Init_ArmosCartControl_x(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosCartControl msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::msg::ArmosCartControl>()
{
  return armos_interfaces::msg::builder::Init_ArmosCartControl_mode();
}

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__BUILDER_HPP_
