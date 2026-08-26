// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armos_interfaces:msg/ArmosCartControl.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_H_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/ArmosCartControl in the package armos_interfaces.
typedef struct armos_interfaces__msg__ArmosCartControl
{
  /// 0 pose 1 vel
  uint8_t mode;
  float x;
  float y;
  float z;
  float a;
  float b;
  float c;
} armos_interfaces__msg__ArmosCartControl;

// Struct for a sequence of armos_interfaces__msg__ArmosCartControl.
typedef struct armos_interfaces__msg__ArmosCartControl__Sequence
{
  armos_interfaces__msg__ArmosCartControl * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__msg__ArmosCartControl__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_CART_CONTROL__STRUCT_H_
