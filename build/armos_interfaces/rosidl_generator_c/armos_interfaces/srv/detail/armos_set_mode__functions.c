// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armos_interfaces:srv/ArmosSetMode.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/srv/detail/armos_set_mode__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `arm_id`
// Member `mode`
#include "rosidl_runtime_c/string_functions.h"

bool
armos_interfaces__srv__ArmosSetMode_Request__init(armos_interfaces__srv__ArmosSetMode_Request * msg)
{
  if (!msg) {
    return false;
  }
  // arm_id
  if (!rosidl_runtime_c__String__init(&msg->arm_id)) {
    armos_interfaces__srv__ArmosSetMode_Request__fini(msg);
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__init(&msg->mode)) {
    armos_interfaces__srv__ArmosSetMode_Request__fini(msg);
    return false;
  }
  return true;
}

void
armos_interfaces__srv__ArmosSetMode_Request__fini(armos_interfaces__srv__ArmosSetMode_Request * msg)
{
  if (!msg) {
    return;
  }
  // arm_id
  rosidl_runtime_c__String__fini(&msg->arm_id);
  // mode
  rosidl_runtime_c__String__fini(&msg->mode);
}

bool
armos_interfaces__srv__ArmosSetMode_Request__are_equal(const armos_interfaces__srv__ArmosSetMode_Request * lhs, const armos_interfaces__srv__ArmosSetMode_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // arm_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->arm_id), &(rhs->arm_id)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mode), &(rhs->mode)))
  {
    return false;
  }
  return true;
}

bool
armos_interfaces__srv__ArmosSetMode_Request__copy(
  const armos_interfaces__srv__ArmosSetMode_Request * input,
  armos_interfaces__srv__ArmosSetMode_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // arm_id
  if (!rosidl_runtime_c__String__copy(
      &(input->arm_id), &(output->arm_id)))
  {
    return false;
  }
  // mode
  if (!rosidl_runtime_c__String__copy(
      &(input->mode), &(output->mode)))
  {
    return false;
  }
  return true;
}

armos_interfaces__srv__ArmosSetMode_Request *
armos_interfaces__srv__ArmosSetMode_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Request * msg = (armos_interfaces__srv__ArmosSetMode_Request *)allocator.allocate(sizeof(armos_interfaces__srv__ArmosSetMode_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armos_interfaces__srv__ArmosSetMode_Request));
  bool success = armos_interfaces__srv__ArmosSetMode_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armos_interfaces__srv__ArmosSetMode_Request__destroy(armos_interfaces__srv__ArmosSetMode_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armos_interfaces__srv__ArmosSetMode_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armos_interfaces__srv__ArmosSetMode_Request__Sequence__init(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Request * data = NULL;

  if (size) {
    data = (armos_interfaces__srv__ArmosSetMode_Request *)allocator.zero_allocate(size, sizeof(armos_interfaces__srv__ArmosSetMode_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armos_interfaces__srv__ArmosSetMode_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armos_interfaces__srv__ArmosSetMode_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
armos_interfaces__srv__ArmosSetMode_Request__Sequence__fini(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      armos_interfaces__srv__ArmosSetMode_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

armos_interfaces__srv__ArmosSetMode_Request__Sequence *
armos_interfaces__srv__ArmosSetMode_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Request__Sequence * array = (armos_interfaces__srv__ArmosSetMode_Request__Sequence *)allocator.allocate(sizeof(armos_interfaces__srv__ArmosSetMode_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armos_interfaces__srv__ArmosSetMode_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armos_interfaces__srv__ArmosSetMode_Request__Sequence__destroy(armos_interfaces__srv__ArmosSetMode_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armos_interfaces__srv__ArmosSetMode_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armos_interfaces__srv__ArmosSetMode_Request__Sequence__are_equal(const armos_interfaces__srv__ArmosSetMode_Request__Sequence * lhs, const armos_interfaces__srv__ArmosSetMode_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armos_interfaces__srv__ArmosSetMode_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armos_interfaces__srv__ArmosSetMode_Request__Sequence__copy(
  const armos_interfaces__srv__ArmosSetMode_Request__Sequence * input,
  armos_interfaces__srv__ArmosSetMode_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armos_interfaces__srv__ArmosSetMode_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armos_interfaces__srv__ArmosSetMode_Request * data =
      (armos_interfaces__srv__ArmosSetMode_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armos_interfaces__srv__ArmosSetMode_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armos_interfaces__srv__ArmosSetMode_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armos_interfaces__srv__ArmosSetMode_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
armos_interfaces__srv__ArmosSetMode_Response__init(armos_interfaces__srv__ArmosSetMode_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  return true;
}

void
armos_interfaces__srv__ArmosSetMode_Response__fini(armos_interfaces__srv__ArmosSetMode_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
}

bool
armos_interfaces__srv__ArmosSetMode_Response__are_equal(const armos_interfaces__srv__ArmosSetMode_Response * lhs, const armos_interfaces__srv__ArmosSetMode_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
armos_interfaces__srv__ArmosSetMode_Response__copy(
  const armos_interfaces__srv__ArmosSetMode_Response * input,
  armos_interfaces__srv__ArmosSetMode_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

armos_interfaces__srv__ArmosSetMode_Response *
armos_interfaces__srv__ArmosSetMode_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Response * msg = (armos_interfaces__srv__ArmosSetMode_Response *)allocator.allocate(sizeof(armos_interfaces__srv__ArmosSetMode_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armos_interfaces__srv__ArmosSetMode_Response));
  bool success = armos_interfaces__srv__ArmosSetMode_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armos_interfaces__srv__ArmosSetMode_Response__destroy(armos_interfaces__srv__ArmosSetMode_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armos_interfaces__srv__ArmosSetMode_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armos_interfaces__srv__ArmosSetMode_Response__Sequence__init(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Response * data = NULL;

  if (size) {
    data = (armos_interfaces__srv__ArmosSetMode_Response *)allocator.zero_allocate(size, sizeof(armos_interfaces__srv__ArmosSetMode_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armos_interfaces__srv__ArmosSetMode_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armos_interfaces__srv__ArmosSetMode_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
armos_interfaces__srv__ArmosSetMode_Response__Sequence__fini(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      armos_interfaces__srv__ArmosSetMode_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

armos_interfaces__srv__ArmosSetMode_Response__Sequence *
armos_interfaces__srv__ArmosSetMode_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__srv__ArmosSetMode_Response__Sequence * array = (armos_interfaces__srv__ArmosSetMode_Response__Sequence *)allocator.allocate(sizeof(armos_interfaces__srv__ArmosSetMode_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armos_interfaces__srv__ArmosSetMode_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armos_interfaces__srv__ArmosSetMode_Response__Sequence__destroy(armos_interfaces__srv__ArmosSetMode_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armos_interfaces__srv__ArmosSetMode_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armos_interfaces__srv__ArmosSetMode_Response__Sequence__are_equal(const armos_interfaces__srv__ArmosSetMode_Response__Sequence * lhs, const armos_interfaces__srv__ArmosSetMode_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armos_interfaces__srv__ArmosSetMode_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armos_interfaces__srv__ArmosSetMode_Response__Sequence__copy(
  const armos_interfaces__srv__ArmosSetMode_Response__Sequence * input,
  armos_interfaces__srv__ArmosSetMode_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armos_interfaces__srv__ArmosSetMode_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armos_interfaces__srv__ArmosSetMode_Response * data =
      (armos_interfaces__srv__ArmosSetMode_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armos_interfaces__srv__ArmosSetMode_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armos_interfaces__srv__ArmosSetMode_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armos_interfaces__srv__ArmosSetMode_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
