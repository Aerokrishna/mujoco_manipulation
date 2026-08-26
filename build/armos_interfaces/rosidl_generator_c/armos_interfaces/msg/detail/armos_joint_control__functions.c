// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armos_interfaces:msg/ArmosJointControl.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/msg/detail/armos_joint_control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
armos_interfaces__msg__ArmosJointControl__init(armos_interfaces__msg__ArmosJointControl * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  // joint1
  // joint2
  // joint3
  // joint4
  // joint5
  // joint6
  // joint7
  return true;
}

void
armos_interfaces__msg__ArmosJointControl__fini(armos_interfaces__msg__ArmosJointControl * msg)
{
  if (!msg) {
    return;
  }
  // mode
  // joint1
  // joint2
  // joint3
  // joint4
  // joint5
  // joint6
  // joint7
}

bool
armos_interfaces__msg__ArmosJointControl__are_equal(const armos_interfaces__msg__ArmosJointControl * lhs, const armos_interfaces__msg__ArmosJointControl * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  // joint1
  if (lhs->joint1 != rhs->joint1) {
    return false;
  }
  // joint2
  if (lhs->joint2 != rhs->joint2) {
    return false;
  }
  // joint3
  if (lhs->joint3 != rhs->joint3) {
    return false;
  }
  // joint4
  if (lhs->joint4 != rhs->joint4) {
    return false;
  }
  // joint5
  if (lhs->joint5 != rhs->joint5) {
    return false;
  }
  // joint6
  if (lhs->joint6 != rhs->joint6) {
    return false;
  }
  // joint7
  if (lhs->joint7 != rhs->joint7) {
    return false;
  }
  return true;
}

bool
armos_interfaces__msg__ArmosJointControl__copy(
  const armos_interfaces__msg__ArmosJointControl * input,
  armos_interfaces__msg__ArmosJointControl * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  // joint1
  output->joint1 = input->joint1;
  // joint2
  output->joint2 = input->joint2;
  // joint3
  output->joint3 = input->joint3;
  // joint4
  output->joint4 = input->joint4;
  // joint5
  output->joint5 = input->joint5;
  // joint6
  output->joint6 = input->joint6;
  // joint7
  output->joint7 = input->joint7;
  return true;
}

armos_interfaces__msg__ArmosJointControl *
armos_interfaces__msg__ArmosJointControl__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosJointControl * msg = (armos_interfaces__msg__ArmosJointControl *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosJointControl), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armos_interfaces__msg__ArmosJointControl));
  bool success = armos_interfaces__msg__ArmosJointControl__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armos_interfaces__msg__ArmosJointControl__destroy(armos_interfaces__msg__ArmosJointControl * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armos_interfaces__msg__ArmosJointControl__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armos_interfaces__msg__ArmosJointControl__Sequence__init(armos_interfaces__msg__ArmosJointControl__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosJointControl * data = NULL;

  if (size) {
    data = (armos_interfaces__msg__ArmosJointControl *)allocator.zero_allocate(size, sizeof(armos_interfaces__msg__ArmosJointControl), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armos_interfaces__msg__ArmosJointControl__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armos_interfaces__msg__ArmosJointControl__fini(&data[i - 1]);
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
armos_interfaces__msg__ArmosJointControl__Sequence__fini(armos_interfaces__msg__ArmosJointControl__Sequence * array)
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
      armos_interfaces__msg__ArmosJointControl__fini(&array->data[i]);
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

armos_interfaces__msg__ArmosJointControl__Sequence *
armos_interfaces__msg__ArmosJointControl__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosJointControl__Sequence * array = (armos_interfaces__msg__ArmosJointControl__Sequence *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosJointControl__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armos_interfaces__msg__ArmosJointControl__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armos_interfaces__msg__ArmosJointControl__Sequence__destroy(armos_interfaces__msg__ArmosJointControl__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armos_interfaces__msg__ArmosJointControl__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armos_interfaces__msg__ArmosJointControl__Sequence__are_equal(const armos_interfaces__msg__ArmosJointControl__Sequence * lhs, const armos_interfaces__msg__ArmosJointControl__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armos_interfaces__msg__ArmosJointControl__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armos_interfaces__msg__ArmosJointControl__Sequence__copy(
  const armos_interfaces__msg__ArmosJointControl__Sequence * input,
  armos_interfaces__msg__ArmosJointControl__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armos_interfaces__msg__ArmosJointControl);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armos_interfaces__msg__ArmosJointControl * data =
      (armos_interfaces__msg__ArmosJointControl *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armos_interfaces__msg__ArmosJointControl__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armos_interfaces__msg__ArmosJointControl__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armos_interfaces__msg__ArmosJointControl__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
