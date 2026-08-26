// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__FUNCTIONS_H_
#define ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "armos_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "armos_interfaces/msg/detail/armos_telemetry__struct.h"

/// Initialize msg/ArmosTelemetry message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * armos_interfaces__msg__ArmosTelemetry
 * )) before or use
 * armos_interfaces__msg__ArmosTelemetry__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__init(armos_interfaces__msg__ArmosTelemetry * msg);

/// Finalize msg/ArmosTelemetry message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__msg__ArmosTelemetry__fini(armos_interfaces__msg__ArmosTelemetry * msg);

/// Create msg/ArmosTelemetry message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * armos_interfaces__msg__ArmosTelemetry__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__msg__ArmosTelemetry *
armos_interfaces__msg__ArmosTelemetry__create();

/// Destroy msg/ArmosTelemetry message.
/**
 * It calls
 * armos_interfaces__msg__ArmosTelemetry__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__msg__ArmosTelemetry__destroy(armos_interfaces__msg__ArmosTelemetry * msg);

/// Check for msg/ArmosTelemetry message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__are_equal(const armos_interfaces__msg__ArmosTelemetry * lhs, const armos_interfaces__msg__ArmosTelemetry * rhs);

/// Copy a msg/ArmosTelemetry message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__copy(
  const armos_interfaces__msg__ArmosTelemetry * input,
  armos_interfaces__msg__ArmosTelemetry * output);

/// Initialize array of msg/ArmosTelemetry messages.
/**
 * It allocates the memory for the number of elements and calls
 * armos_interfaces__msg__ArmosTelemetry__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__Sequence__init(armos_interfaces__msg__ArmosTelemetry__Sequence * array, size_t size);

/// Finalize array of msg/ArmosTelemetry messages.
/**
 * It calls
 * armos_interfaces__msg__ArmosTelemetry__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__msg__ArmosTelemetry__Sequence__fini(armos_interfaces__msg__ArmosTelemetry__Sequence * array);

/// Create array of msg/ArmosTelemetry messages.
/**
 * It allocates the memory for the array and calls
 * armos_interfaces__msg__ArmosTelemetry__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__msg__ArmosTelemetry__Sequence *
armos_interfaces__msg__ArmosTelemetry__Sequence__create(size_t size);

/// Destroy array of msg/ArmosTelemetry messages.
/**
 * It calls
 * armos_interfaces__msg__ArmosTelemetry__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__msg__ArmosTelemetry__Sequence__destroy(armos_interfaces__msg__ArmosTelemetry__Sequence * array);

/// Check for msg/ArmosTelemetry message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__Sequence__are_equal(const armos_interfaces__msg__ArmosTelemetry__Sequence * lhs, const armos_interfaces__msg__ArmosTelemetry__Sequence * rhs);

/// Copy an array of msg/ArmosTelemetry messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__msg__ArmosTelemetry__Sequence__copy(
  const armos_interfaces__msg__ArmosTelemetry__Sequence * input,
  armos_interfaces__msg__ArmosTelemetry__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__MSG__DETAIL__ARMOS_TELEMETRY__FUNCTIONS_H_
