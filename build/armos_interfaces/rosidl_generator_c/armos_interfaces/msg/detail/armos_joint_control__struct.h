// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_H_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmosJointControl in the package armos_interfaces.
typedef struct armos_interfaces__msg__ArmosJointControl
{
  /// 0 position 1 velocity 2 torque
  uint8_t mode;
  float joint1;
  float joint2;
  float joint3;
  float joint4;
  float joint5;
  float joint6;
  float joint7;
} armos_interfaces__msg__ArmosJointControl;

// Struct for a sequence of armos_interfaces__msg__ArmosJointControl.
typedef struct armos_interfaces__msg__ArmosJointControl__Sequence
{
  armos_interfaces__msg__ArmosJointControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__msg__ArmosJointControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_JOINT_CONTROL__STRUCT_H_
