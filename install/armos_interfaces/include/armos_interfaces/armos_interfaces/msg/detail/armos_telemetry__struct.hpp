// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armos_interfaces__msg__ArmosTelemetry __attribute__((deprecated))
#else
# define DEPRECATED__armos_interfaces__msg__ArmosTelemetry __declspec(deprecated)
#endif

namespace armos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmosTelemetry_
{
  using Type = ArmosTelemetry_<ContainerAllocator>;

  explicit ArmosTelemetry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0.0f;
      this->manipulability = 0.0f;
      this->singularity_distance = 0.0f;
    }
  }

  explicit ArmosTelemetry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->timestamp = 0.0f;
      this->manipulability = 0.0f;
      this->singularity_distance = 0.0f;
    }
  }

  // field types and members
  using _timestamp_type =
    float;
  _timestamp_type timestamp;
  using _joint_pos_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_pos_type joint_pos;
  using _joint_vel_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_vel_type joint_vel;
  using _joint_torque_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _joint_torque_type joint_torque;
  using _wrench_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _wrench_type wrench;
  using _tcp_pose_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _tcp_pose_type tcp_pose;
  using _tcp_twist_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _tcp_twist_type tcp_twist;
  using _manipulability_type =
    float;
  _manipulability_type manipulability;
  using _singularity_distance_type =
    float;
  _singularity_distance_type singularity_distance;

  // setters for named parameter idiom
  Type & set__timestamp(
    const float & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__joint_pos(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->joint_pos = _arg;
    return *this;
  }
  Type & set__joint_vel(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->joint_vel = _arg;
    return *this;
  }
  Type & set__joint_torque(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->joint_torque = _arg;
    return *this;
  }
  Type & set__wrench(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->wrench = _arg;
    return *this;
  }
  Type & set__tcp_pose(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->tcp_pose = _arg;
    return *this;
  }
  Type & set__tcp_twist(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->tcp_twist = _arg;
    return *this;
  }
  Type & set__manipulability(
    const float & _arg)
  {
    this->manipulability = _arg;
    return *this;
  }
  Type & set__singularity_distance(
    const float & _arg)
  {
    this->singularity_distance = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> *;
  using ConstRawPtr =
    const armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armos_interfaces__msg__ArmosTelemetry
    std::shared_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armos_interfaces__msg__ArmosTelemetry
    std::shared_ptr<armos_interfaces::msg::ArmosTelemetry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmosTelemetry_ & other) const
  {
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->joint_pos != other.joint_pos) {
      return false;
    }
    if (this->joint_vel != other.joint_vel) {
      return false;
    }
    if (this->joint_torque != other.joint_torque) {
      return false;
    }
    if (this->wrench != other.wrench) {
      return false;
    }
    if (this->tcp_pose != other.tcp_pose) {
      return false;
    }
    if (this->tcp_twist != other.tcp_twist) {
      return false;
    }
    if (this->manipulability != other.manipulability) {
      return false;
    }
    if (this->singularity_distance != other.singularity_distance) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmosTelemetry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmosTelemetry_

// alias to use template instance with default allocator
using ArmosTelemetry =
  armos_interfaces::msg::ArmosTelemetry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_HPP_
