// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from armos_interfaces:srv/ArmosSetMode.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_HPP_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__armos_interfaces__srv__ArmosSetMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__armos_interfaces__srv__ArmosSetMode_Request __declspec(deprecated)
#endif

namespace armos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmosSetMode_Request_
{
  using Type = ArmosSetMode_Request_<ContainerAllocator>;

  explicit ArmosSetMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arm_id = "";
      this->mode = "";
    }
  }

  explicit ArmosSetMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : arm_id(_alloc),
    mode(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->arm_id = "";
      this->mode = "";
    }
  }

  // field types and members
  using _arm_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _arm_id_type arm_id;
  using _mode_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__arm_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->arm_id = _arg;
    return *this;
  }
  Type & set__mode(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armos_interfaces__srv__ArmosSetMode_Request
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armos_interfaces__srv__ArmosSetMode_Request
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmosSetMode_Request_ & other) const
  {
    if (this->arm_id != other.arm_id) {
      return false;
    }
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmosSetMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmosSetMode_Request_

// alias to use template instance with default allocator
using ArmosSetMode_Request =
  armos_interfaces::srv::ArmosSetMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace armos_interfaces


#ifndef _WIN32
# define DEPRECATED__armos_interfaces__srv__ArmosSetMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__armos_interfaces__srv__ArmosSetMode_Response __declspec(deprecated)
#endif

namespace armos_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ArmosSetMode_Response_
{
  using Type = ArmosSetMode_Response_<ContainerAllocator>;

  explicit ArmosSetMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit ArmosSetMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__armos_interfaces__srv__ArmosSetMode_Response
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__armos_interfaces__srv__ArmosSetMode_Response
    std::shared_ptr<armos_interfaces::srv::ArmosSetMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArmosSetMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArmosSetMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArmosSetMode_Response_

// alias to use template instance with default allocator
using ArmosSetMode_Response =
  armos_interfaces::srv::ArmosSetMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace armos_interfaces

namespace armos_interfaces
{

namespace srv
{

struct ArmosSetMode
{
  using Request = armos_interfaces::srv::ArmosSetMode_Request;
  using Response = armos_interfaces::srv::ArmosSetMode_Response;
};

}  // namespace srv

}  // namespace armos_interfaces

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_HPP_
