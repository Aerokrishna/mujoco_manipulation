// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from armos_interfaces:srv/ArmosSetMode.idl
// generated code does not contain a copyright notice

#ifndef ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__FUNCTIONS_H_
#define ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "armos_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "armos_interfaces/srv/detail/armos_set_mode__struct.h"

/// Initialize srv/ArmosSetMode message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * armos_interfaces__srv__ArmosSetMode_Request
 * )) before or use
 * armos_interfaces__srv__ArmosSetMode_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Request__init(armos_interfaces__srv__ArmosSetMode_Request * msg);

/// Finalize srv/ArmosSetMode message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Request__fini(armos_interfaces__srv__ArmosSetMode_Request * msg);

/// Create srv/ArmosSetMode message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * armos_interfaces__srv__ArmosSetMode_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__srv__ArmosSetMode_Request *
armos_interfaces__srv__ArmosSetMode_Request__create();

/// Destroy srv/ArmosSetMode message.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Request__destroy(armos_interfaces__srv__ArmosSetMode_Request * msg);

/// Check for srv/ArmosSetMode message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Request__are_equal(const armos_interfaces__srv__ArmosSetMode_Request * lhs, const armos_interfaces__srv__ArmosSetMode_Request * rhs);

/// Copy a srv/ArmosSetMode message.
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
armos_interfaces__srv__ArmosSetMode_Request__copy(
  const armos_interfaces__srv__ArmosSetMode_Request * input,
  armos_interfaces__srv__ArmosSetMode_Request * output);

/// Initialize array of srv/ArmosSetMode messages.
/**
 * It allocates the memory for the number of elements and calls
 * armos_interfaces__srv__ArmosSetMode_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Request__Sequence__init(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array, size_t size);

/// Finalize array of srv/ArmosSetMode messages.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Request__Sequence__fini(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array);

/// Create array of srv/ArmosSetMode messages.
/**
 * It allocates the memory for the array and calls
 * armos_interfaces__srv__ArmosSetMode_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__srv__ArmosSetMode_Request__Sequence *
armos_interfaces__srv__ArmosSetMode_Request__Sequence__create(size_t size);

/// Destroy array of srv/ArmosSetMode messages.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Request__Sequence__destroy(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array);

/// Check for srv/ArmosSetMode message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Request__Sequence__are_equal(const armos_interfaces__srv__ArmosSetMode_Request__Sequence * lhs, const armos_interfaces__srv__ArmosSetMode_Request__Sequence * rhs);

/// Copy an array of srv/ArmosSetMode messages.
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
armos_interfaces__srv__ArmosSetMode_Request__Sequence__copy(
  const armos_interfaces__srv__ArmosSetMode_Request__Sequence * input,
  armos_interfaces__srv__ArmosSetMode_Request__Sequence * output);

/// Initialize srv/ArmosSetMode message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * armos_interfaces__srv__ArmosSetMode_Response
 * )) before or use
 * armos_interfaces__srv__ArmosSetMode_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Response__init(armos_interfaces__srv__ArmosSetMode_Response * msg);

/// Finalize srv/ArmosSetMode message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Response__fini(armos_interfaces__srv__ArmosSetMode_Response * msg);

/// Create srv/ArmosSetMode message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * armos_interfaces__srv__ArmosSetMode_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__srv__ArmosSetMode_Response *
armos_interfaces__srv__ArmosSetMode_Response__create();

/// Destroy srv/ArmosSetMode message.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Response__destroy(armos_interfaces__srv__ArmosSetMode_Response * msg);

/// Check for srv/ArmosSetMode message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Response__are_equal(const armos_interfaces__srv__ArmosSetMode_Response * lhs, const armos_interfaces__srv__ArmosSetMode_Response * rhs);

/// Copy a srv/ArmosSetMode message.
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
armos_interfaces__srv__ArmosSetMode_Response__copy(
  const armos_interfaces__srv__ArmosSetMode_Response * input,
  armos_interfaces__srv__ArmosSetMode_Response * output);

/// Initialize array of srv/ArmosSetMode messages.
/**
 * It allocates the memory for the number of elements and calls
 * armos_interfaces__srv__ArmosSetMode_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Response__Sequence__init(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array, size_t size);

/// Finalize array of srv/ArmosSetMode messages.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Response__Sequence__fini(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array);

/// Create array of srv/ArmosSetMode messages.
/**
 * It allocates the memory for the array and calls
 * armos_interfaces__srv__ArmosSetMode_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
armos_interfaces__srv__ArmosSetMode_Response__Sequence *
armos_interfaces__srv__ArmosSetMode_Response__Sequence__create(size_t size);

/// Destroy array of srv/ArmosSetMode messages.
/**
 * It calls
 * armos_interfaces__srv__ArmosSetMode_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
void
armos_interfaces__srv__ArmosSetMode_Response__Sequence__destroy(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array);

/// Check for srv/ArmosSetMode message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_armos_interfaces
bool
armos_interfaces__srv__ArmosSetMode_Response__Sequence__are_equal(const armos_interfaces__srv__ArmosSetMode_Response__Sequence * lhs, const armos_interfaces__srv__ArmosSetMode_Response__Sequence * rhs);

/// Copy an array of srv/ArmosSetMode messages.
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
armos_interfaces__srv__ArmosSetMode_Response__Sequence__copy(
  const armos_interfaces__srv__ArmosSetMode_Response__Sequence * input,
  armos_interfaces__srv__ArmosSetMode_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // ARMOS_INTERFACES__SRV__DETAIL__ARMOS_SET_MODE__FUNCTIONS_H_
