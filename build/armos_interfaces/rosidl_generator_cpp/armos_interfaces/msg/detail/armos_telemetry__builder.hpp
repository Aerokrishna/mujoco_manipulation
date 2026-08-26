// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__BUILDER_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "armos_interfaces/msg/detail/armos_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace armos_interfaces
{

namespace msg
{

namespace builder
{

class Init_ArmosTelemetry_singularity_distance
{
public:
  explicit Init_ArmosTelemetry_singularity_distance(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  ::armos_interfaces::msg::ArmosTelemetry singularity_distance(::armos_interfaces::msg::ArmosTelemetry::_singularity_distance_type arg)
  {
    msg_.singularity_distance = std::move(arg);
    return std::move(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_manipulability
{
public:
  explicit Init_ArmosTelemetry_manipulability(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_singularity_distance manipulability(::armos_interfaces::msg::ArmosTelemetry::_manipulability_type arg)
  {
    msg_.manipulability = std::move(arg);
    return Init_ArmosTelemetry_singularity_distance(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_tcp_twist
{
public:
  explicit Init_ArmosTelemetry_tcp_twist(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_manipulability tcp_twist(::armos_interfaces::msg::ArmosTelemetry::_tcp_twist_type arg)
  {
    msg_.tcp_twist = std::move(arg);
    return Init_ArmosTelemetry_manipulability(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_tcp_pose
{
public:
  explicit Init_ArmosTelemetry_tcp_pose(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_tcp_twist tcp_pose(::armos_interfaces::msg::ArmosTelemetry::_tcp_pose_type arg)
  {
    msg_.tcp_pose = std::move(arg);
    return Init_ArmosTelemetry_tcp_twist(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_wrench
{
public:
  explicit Init_ArmosTelemetry_wrench(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_tcp_pose wrench(::armos_interfaces::msg::ArmosTelemetry::_wrench_type arg)
  {
    msg_.wrench = std::move(arg);
    return Init_ArmosTelemetry_tcp_pose(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_joint_torque
{
public:
  explicit Init_ArmosTelemetry_joint_torque(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_wrench joint_torque(::armos_interfaces::msg::ArmosTelemetry::_joint_torque_type arg)
  {
    msg_.joint_torque = std::move(arg);
    return Init_ArmosTelemetry_wrench(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_joint_vel
{
public:
  explicit Init_ArmosTelemetry_joint_vel(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_joint_torque joint_vel(::armos_interfaces::msg::ArmosTelemetry::_joint_vel_type arg)
  {
    msg_.joint_vel = std::move(arg);
    return Init_ArmosTelemetry_joint_torque(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_joint_pos
{
public:
  explicit Init_ArmosTelemetry_joint_pos(::armos_interfaces::msg::ArmosTelemetry & msg)
  : msg_(msg)
  {}
  Init_ArmosTelemetry_joint_vel joint_pos(::armos_interfaces::msg::ArmosTelemetry::_joint_pos_type arg)
  {
    msg_.joint_pos = std::move(arg);
    return Init_ArmosTelemetry_joint_vel(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

class Init_ArmosTelemetry_timestamp
{
public:
  Init_ArmosTelemetry_timestamp()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmosTelemetry_joint_pos timestamp(::armos_interfaces::msg::ArmosTelemetry::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_ArmosTelemetry_joint_pos(msg_);
  }

private:
  ::armos_interfaces::msg::ArmosTelemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::armos_interfaces::msg::ArmosTelemetry>()
{
  return armos_interfaces::msg::builder::Init_ArmosTelemetry_timestamp();
}

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__BUILDER_HPP_
