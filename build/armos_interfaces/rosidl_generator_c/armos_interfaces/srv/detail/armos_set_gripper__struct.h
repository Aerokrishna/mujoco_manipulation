// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armos_interfaces:srv/ArmosSetGripper.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__STRUCT_H_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/ArmosSetGripper in the package armos_interfaces.
typedef struct armos_interfaces__srv__ArmosSetGripper_Request
{
  /// 0 to 1
  float position;
} armos_interfaces__srv__ArmosSetGripper_Request;

// Struct for a sequence of armos_interfaces__srv__ArmosSetGripper_Request.
typedef struct armos_interfaces__srv__ArmosSetGripper_Request__Sequence
{
  armos_interfaces__srv__ArmosSetGripper_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__srv__ArmosSetGripper_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ArmosSetGripper in the package armos_interfaces.
typedef struct armos_interfaces__srv__ArmosSetGripper_Response
{
  bool success;
  rosidl_runtime_c__String message;
} armos_interfaces__srv__ArmosSetGripper_Response;

// Struct for a sequence of armos_interfaces__srv__ArmosSetGripper_Response.
typedef struct armos_interfaces__srv__ArmosSetGripper_Response__Sequence
{
  armos_interfaces__srv__ArmosSetGripper_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__srv__ArmosSetGripper_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_GRIPPER__STRUCT_H_
