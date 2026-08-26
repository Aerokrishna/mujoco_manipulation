// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__TRAITS_HPP_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "armos_interfaces/msg/detail/armos_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace armos_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const ArmosTelemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: joint_pos
  {
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []";
    } else {
      out << "joint_pos: [";
      size_t pending_items = msg.joint_pos.size();
      for (auto item : msg.joint_pos) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_vel
  {
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []";
    } else {
      out << "joint_vel: [";
      size_t pending_items = msg.joint_vel.size();
      for (auto item : msg.joint_vel) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: joint_torque
  {
    if (msg.joint_torque.size() == 0) {
      out << "joint_torque: []";
    } else {
      out << "joint_torque: [";
      size_t pending_items = msg.joint_torque.size();
      for (auto item : msg.joint_torque) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: wrench
  {
    if (msg.wrench.size() == 0) {
      out << "wrench: []";
    } else {
      out << "wrench: [";
      size_t pending_items = msg.wrench.size();
      for (auto item : msg.wrench) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tcp_pose
  {
    if (msg.tcp_pose.size() == 0) {
      out << "tcp_pose: []";
    } else {
      out << "tcp_pose: [";
      size_t pending_items = msg.tcp_pose.size();
      for (auto item : msg.tcp_pose) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: tcp_twist
  {
    if (msg.tcp_twist.size() == 0) {
      out << "tcp_twist: []";
    } else {
      out << "tcp_twist: [";
      size_t pending_items = msg.tcp_twist.size();
      for (auto item : msg.tcp_twist) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: manipulability
  {
    out << "manipulability: ";
    rosidl_generator_traits::value_to_yaml(msg.manipulability, out);
    out << ", ";
  }

  // member: singularity_distance
  {
    out << "singularity_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.singularity_distance, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ArmosTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: joint_pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_pos.size() == 0) {
      out << "joint_pos: []\n";
    } else {
      out << "joint_pos:\n";
      for (auto item : msg.joint_pos) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_vel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_vel.size() == 0) {
      out << "joint_vel: []\n";
    } else {
      out << "joint_vel:\n";
      for (auto item : msg.joint_vel) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: joint_torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.joint_torque.size() == 0) {
      out << "joint_torque: []\n";
    } else {
      out << "joint_torque:\n";
      for (auto item : msg.joint_torque) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: wrench
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.wrench.size() == 0) {
      out << "wrench: []\n";
    } else {
      out << "wrench:\n";
      for (auto item : msg.wrench) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tcp_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tcp_pose.size() == 0) {
      out << "tcp_pose: []\n";
    } else {
      out << "tcp_pose:\n";
      for (auto item : msg.tcp_pose) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: tcp_twist
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.tcp_twist.size() == 0) {
      out << "tcp_twist: []\n";
    } else {
      out << "tcp_twist:\n";
      for (auto item : msg.tcp_twist) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: manipulability
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "manipulability: ";
    rosidl_generator_traits::value_to_yaml(msg.manipulability, out);
    out << "\n";
  }

  // member: singularity_distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "singularity_distance: ";
    rosidl_generator_traits::value_to_yaml(msg.singularity_distance, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ArmosTelemetry & msg, bool use_flow_style = false)
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
  const armos_interfaces::msg::ArmosTelemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  armos_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use armos_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const armos_interfaces::msg::ArmosTelemetry & msg)
{
  return armos_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<armos_interfaces::msg::ArmosTelemetry>()
{
  return "armos_interfaces::msg::ArmosTelemetry";
}

template<>
inline const char * name<armos_interfaces::msg::ArmosTelemetry>()
{
  return "armos_interfaces/msg/ArmosTelemetry";
}

template<>
struct has_fixed_size<armos_interfaces::msg::ArmosTelemetry>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<armos_interfaces::msg::ArmosTelemetry>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<armos_interfaces::msg::ArmosTelemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__TRAITS_HPP_
