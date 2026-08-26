// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armos_interfaces:srv/ArmosSetGripper.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__TRAITS_HPP_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armos_interfaces/srv/detail/armos_set_gripper__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ArmosSetGripper_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmosSetGripper_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmosSetGripper_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace armos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armos_interfaces::srv::ArmosSetGripper_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  armos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const armos_interfaces::srv::ArmosSetGripper_Request & msg)
{
  return armos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<armos_interfaces::srv::ArmosSetGripper_Request>()
{
  return "armos_interfaces::srv::ArmosSetGripper_Request";
}

template<>
inline const char * name<armos_interfaces::srv::ArmosSetGripper_Request>()
{
  return "armos_interfaces/srv/ArmosSetGripper_Request";
}

template<>
struct has_fixed_size<armos_interfaces::srv::ArmosSetGripper_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<armos_interfaces::srv::ArmosSetGripper_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<armos_interfaces::srv::ArmosSetGripper_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace armos_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const ArmosSetGripper_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmosSetGripper_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmosSetGripper_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace armos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armos_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armos_interfaces::srv::ArmosSetGripper_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  armos_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armos_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const armos_interfaces::srv::ArmosSetGripper_Response & msg)
{
  return armos_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<armos_interfaces::srv::ArmosSetGripper_Response>()
{
  return "armos_interfaces::srv::ArmosSetGripper_Response";
}

template<>
inline const char * name<armos_interfaces::srv::ArmosSetGripper_Response>()
{
  return "armos_interfaces/srv/ArmosSetGripper_Response";
}

template<>
struct has_fixed_size<armos_interfaces::srv::ArmosSetGripper_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<armos_interfaces::srv::ArmosSetGripper_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<armos_interfaces::srv::ArmosSetGripper_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<armos_interfaces::srv::ArmosSetGripper>()
{
  return "armos_interfaces::srv::ArmosSetGripper";
}

template<>
inline const char * name<armos_interfaces::srv::ArmosSetGripper>()
{
  return "armos_interfaces/srv/ArmosSetGripper";
}

template<>
struct has_fixed_size<armos_interfaces::srv::ArmosSetGripper>
  : std::integral_constant<
    bool,
    has_fixed_size<armos_interfaces::srv::ArmosSetGripper_Request>::value &&
    has_fixed_size<armos_interfaces::srv::ArmosSetGripper_Response>::value
  >
{
};

template<>
struct has_bounded_size<armos_interfaces::srv::ArmosSetGripper>
  : std::integral_constant<
    bool,
    has_bounded_size<armos_interfaces::srv::ArmosSetGripper_Request>::value &&
    has_bounded_size<armos_interfaces::srv::ArmosSetGripper_Response>::value
  >
{
};

template<>
struct is_service<armos_interfaces::srv::ArmosSetGripper>
  : std::true_type
{
};

template<>
struct is_service_request<armos_interfaces::srv::ArmosSetGripper_Request>
  : std::true_type
{
};

template<>
struct is_service_response<armos_interfaces::srv::ArmosSetGripper_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__TRAITS_HPP_
