// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_H_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint_pos'
// Member 'joint_vel'
// Member 'joint_torque'
// Member 'wrench'
// Member 'tcp_pose'
// Member 'tcp_twist'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/ArmosTelemetry in the package armos_interfaces.
typedef struct armos_interfaces__msg__ArmosTelemetry
{
  float timestamp;
  rosidl_runtime_c__float__Sequence joint_pos;
  rosidl_runtime_c__float__Sequence joint_vel;
  rosidl_runtime_c__float__Sequence joint_torque;
  rosidl_runtime_c__float__Sequence wrench;
  rosidl_runtime_c__float__Sequence tcp_pose;
  rosidl_runtime_c__float__Sequence tcp_twist;
  float manipulability;
  float singularity_distance;
} armos_interfaces__msg__ArmosTelemetry;

// Struct for a sequence of armos_interfaces__msg__ArmosTelemetry.
typedef struct armos_interfaces__msg__ArmosTelemetry__Sequence
{
  armos_interfaces__msg__ArmosTelemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__msg__ArmosTelemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__STRUCT_H_
