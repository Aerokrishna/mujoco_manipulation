// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armos_interfaces__msg__ArmosJointControl __attribute__((deprecated))
#else
# define DEPRECATED__armos_interfaces__msg__ArmosJointControl __declspec(deprecated)
#endif

namespace armos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmosJointControl_
{
  using Type = ArmosJointControl_<ContainerAllocator>;

  explicit ArmosJointControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->joint1 = 0.0f;
      this->joint2 = 0.0f;
      this->joint3 = 0.0f;
      this->joint4 = 0.0f;
      this->joint5 = 0.0f;
      this->joint6 = 0.0f;
      this->joint7 = 0.0f;
    }
  }

  explicit ArmosJointControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->joint1 = 0.0f;
      this->joint2 = 0.0f;
      this->joint3 = 0.0f;
      this->joint4 = 0.0f;
      this->joint5 = 0.0f;
      this->joint6 = 0.0f;
      this->joint7 = 0.0f;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _joint1_type =
    float;
  _joint1_type joint1;
  using _joint2_type =
    float;
  _joint2_type joint2;
  using _joint3_type =
    float;
  _joint3_type joint3;
  using _joint4_type =
    float;
  _joint4_type joint4;
  using _joint5_type =
    float;
  _joint5_type joint5;
  using _joint6_type =
    float;
  _joint6_type joint6;
  using _joint7_type =
    float;
  _joint7_type joint7;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__joint1(
    const float & _arg)
  {
    this->joint1 = _arg;
    return *this;
  }
  Type & set__joint2(
    const float & _arg)
  {
    this->joint2 = _arg;
    return *this;
  }
  Type & set__joint3(
    const float & _arg)
  {
    this->joint3 = _arg;
    return *this;
  }
  Type & set__joint4(
    const float & _arg)
  {
    this->joint4 = _arg;
    return *this;
  }
  Type & set__joint5(
    const float & _arg)
  {
    this->joint5 = _arg;
    return *this;
  }
  Type & set__joint6(
    const float & _arg)
  {
    this->joint6 = _arg;
    return *this;
  }
  Type & set__joint7(
    const float & _arg)
  {
    this->joint7 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armos_interfaces__msg__ArmosJointControl
    std::shared_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armos_interfaces__msg__ArmosJointControl
    std::shared_ptr<armos_interfaces::msg::ArmosJointControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmosJointControl_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->joint1 != other.joint1) {
      return false;
    }
    if (this->joint2 != other.joint2) {
      return false;
    }
    if (this->joint3 != other.joint3) {
      return false;
    }
    if (this->joint4 != other.joint4) {
      return false;
    }
    if (this->joint5 != other.joint5) {
      return false;
    }
    if (this->joint6 != other.joint6) {
      return false;
    }
    if (this->joint7 != other.joint7) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmosJointControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmosJointControl_

// alias to use template instance with default allocator
using ArmosJointControl =
  armos_interfaces::msg::ArmosJointControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_HPP_
