// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armos_interfaces:msg/ArmosCartControl.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/msg/detail/armos_cart_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armos_interfaces__msg__ArmosCartControl__init(armos_interfaces__msg__ArmosCartControl * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // x
  // y
  // z
  // a
  // b
  // c
  return true;
}

void
armos_interfaces__msg__ArmosCartControl__fini(armos_interfaces__msg__ArmosCartControl * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // x
  // y
  // z
  // a
  // b
  // c
}

bool
armos_interfaces__msg__ArmosCartControl__are_equal(const armos_interfaces__msg__ArmosCartControl * lhs, const armos_interfaces__msg__ArmosCartControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // a
  if (lhs->a != rhs->a) {
    return false;
  }
  // b
  if (lhs->b != rhs->b) {
    return false;
  }
  // c
  if (lhs->c != rhs->c) {
    return false;
  }
  return true;
}

bool
armos_interfaces__msg__ArmosCartControl__copy(
  const armos_interfaces__msg__ArmosCartControl * input,
  armos_interfaces__msg__ArmosCartControl * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // a
  output->a = input->a;
  // b
  output->b = input->b;
  // c
  output->c = input->c;
  return true;
}

armos_interfaces__msg__ArmosCartControl *
armos_interfaces__msg__ArmosCartControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosCartControl * msg = (armos_interfaces__msg__ArmosCartControl *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosCartControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armos_interfaces__msg__ArmosCartControl));
  bool success = armos_interfaces__msg__ArmosCartControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armos_interfaces__msg__ArmosCartControl__destroy(armos_interfaces__msg__ArmosCartControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armos_interfaces__msg__ArmosCartControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armos_interfaces__msg__ArmosCartControl__Sequence__init(armos_interfaces__msg__ArmosCartControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosCartControl * data = NULL;

  if (size) {
    data = (armos_interfaces__msg__ArmosCartControl *)allocator.zero_allocate(size, sizeof(armos_interfaces__msg__ArmosCartControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armos_interfaces__msg__ArmosCartControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armos_interfaces__msg__ArmosCartControl__fini(&data[i - 1]);
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
armos_interfaces__msg__ArmosCartControl__Sequence__fini(armos_interfaces__msg__ArmosCartControl__Sequence * array)
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
      armos_interfaces__msg__ArmosCartControl__fini(&array->data[i]);
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

armos_interfaces__msg__ArmosCartControl__Sequence *
armos_interfaces__msg__ArmosCartControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosCartControl__Sequence * array = (armos_interfaces__msg__ArmosCartControl__Sequence *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosCartControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armos_interfaces__msg__ArmosCartControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armos_interfaces__msg__ArmosCartControl__Sequence__destroy(armos_interfaces__msg__ArmosCartControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armos_interfaces__msg__ArmosCartControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armos_interfaces__msg__ArmosCartControl__Sequence__are_equal(const armos_interfaces__msg__ArmosCartControl__Sequence * lhs, const armos_interfaces__msg__ArmosCartControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armos_interfaces__msg__ArmosCartControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armos_interfaces__msg__ArmosCartControl__Sequence__copy(
  const armos_interfaces__msg__ArmosCartControl__Sequence * input,
  armos_interfaces__msg__ArmosCartControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armos_interfaces__msg__ArmosCartControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armos_interfaces__msg__ArmosCartControl * data =
      (armos_interfaces__msg__ArmosCartControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armos_interfaces__msg__ArmosCartControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armos_interfaces__msg__ArmosCartControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armos_interfaces__msg__ArmosCartControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
