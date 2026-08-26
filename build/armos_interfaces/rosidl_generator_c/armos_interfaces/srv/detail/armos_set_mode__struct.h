// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from armos_interfaces:srv/ArmosSetMode.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_H_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'arm_id'
// Member 'mode'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/ArmosSetMode in the package armos_interfaces.
typedef struct armos_interfaces__srv__ArmosSetMode_Request
{
  /// the arm you will be passing to
  rosidl_runtime_c__String arm_id;
  rosidl_runtime_c__String mode;
} armos_interfaces__srv__ArmosSetMode_Request;

// Struct for a sequence of armos_interfaces__srv__ArmosSetMode_Request.
typedef struct armos_interfaces__srv__ArmosSetMode_Request__Sequence
{
  armos_interfaces__srv__ArmosSetMode_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__srv__ArmosSetMode_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/ArmosSetMode in the package armos_interfaces.
typedef struct armos_interfaces__srv__ArmosSetMode_Response
{
  /// true if task completed
  bool success;
} armos_interfaces__srv__ArmosSetMode_Response;

// Struct for a sequence of armos_interfaces__srv__ArmosSetMode_Response.
typedef struct armos_interfaces__srv__ArmosSetMode_Response__Sequence
{
  armos_interfaces__srv__ArmosSetMode_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} armos_interfaces__srv__ArmosSetMode_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__STRUCT_H_
