// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armos_interfaces:msg/ArmosCartControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__TRAITS_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armos_interfaces/msg/detail/armos_cart_control__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmosCartControl & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << ", ";
  }

  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: a
  {
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << ", ";
  }

  // member: b
  {
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << ", ";
  }

  // member: c
  {
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmosCartControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }

  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: a
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a: ";
    rosidl_generator_traits::value_to_yaml(msg.a, out);
    out << "\n";
  }

  // member: b
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "b: ";
    rosidl_generator_traits::value_to_yaml(msg.b, out);
    out << "\n";
  }

  // member: c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "c: ";
    rosidl_generator_traits::value_to_yaml(msg.c, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmosCartControl & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace armos_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use armos_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const armos_interfaces::msg::ArmosCartControl & msg,
  std::ostream & out, size_t indentation = 0)
{
  armos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const armos_interfaces::msg::ArmosCartControl & msg)
{
  return armos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<armos_interfaces::msg::ArmosCartControl>()
{
  return "armos_interfaces::msg::ArmosCartControl";
}

template<>
inline const char * name<armos_interfaces::msg::ArmosCartControl>()
{
  return "armos_interfaces/msg/ArmosCartControl";
}

template<>
struct has_fixed_size<armos_interfaces::msg::ArmosCartControl>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<armos_interfaces::msg::ArmosCartControl>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<armos_interfaces::msg::ArmosCartControl>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__TRAITS_HPP_
