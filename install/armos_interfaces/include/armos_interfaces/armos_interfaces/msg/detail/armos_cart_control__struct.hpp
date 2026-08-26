// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armos_interfaces:msg/ArmosCartControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armos_interfaces__msg__ArmosCartControl __attribute__((deprecated))
#else
# define DEPRECATED__armos_interfaces__msg__ArmosCartControl __declspec(deprecated)
#endif

namespace armos_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArmosCartControl_
{
  using Type = ArmosCartControl_<ContainerAllocator>;

  explicit ArmosCartControl_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
    }
  }

  explicit ArmosCartControl_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->a = 0.0f;
      this->b = 0.0f;
      this->c = 0.0f;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _a_type =
    float;
  _a_type a;
  using _b_type =
    float;
  _b_type b;
  using _c_type =
    float;
  _c_type c;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__a(
    const float & _arg)
  {
    this->a = _arg;
    return *this;
  }
  Type & set__b(
    const float & _arg)
  {
    this->b = _arg;
    return *this;
  }
  Type & set__c(
    const float & _arg)
  {
    this->c = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> *;
  using ConstRawPtr =
    const armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armos_interfaces__msg__ArmosCartControl
    std::shared_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armos_interfaces__msg__ArmosCartControl
    std::shared_ptr<armos_interfaces::msg::ArmosCartControl_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmosCartControl_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->a != other.a) {
      return false;
    }
    if (this->b != other.b) {
      return false;
    }
    if (this->c != other.c) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmosCartControl_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmosCartControl_

// alias to use template instance with default allocator
using ArmosCartControl =
  armos_interfaces::msg::ArmosCartControl_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_HPP_
