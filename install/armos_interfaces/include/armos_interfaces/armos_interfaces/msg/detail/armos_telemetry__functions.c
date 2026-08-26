// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/msg/detail/armos_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint_pos`
// Member `joint_vel`
// Member `joint_torque`
// Member `wrench`
// Member `tcp_pose`
// Member `tcp_twist`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
armos_interfaces__msg__ArmosTelemetry__init(armos_interfaces__msg__ArmosTelemetry * msg)
{
  if (!msg) {
    return false;
  }
  // timestamp
  // joint_pos
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_pos, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // joint_vel
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_vel, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // joint_torque
  if (!rosidl_runtime_c__float__Sequence__init(&msg->joint_torque, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // wrench
  if (!rosidl_runtime_c__float__Sequence__init(&msg->wrench, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // tcp_pose
  if (!rosidl_runtime_c__float__Sequence__init(&msg->tcp_pose, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // tcp_twist
  if (!rosidl_runtime_c__float__Sequence__init(&msg->tcp_twist, 0)) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
    return false;
  }
  // manipulability
  // singularity_distance
  return true;
}

void
armos_interfaces__msg__ArmosTelemetry__fini(armos_interfaces__msg__ArmosTelemetry * msg)
{
  if (!msg) {
    return;
  }
  // timestamp
  // joint_pos
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_pos);
  // joint_vel
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_vel);
  // joint_torque
  rosidl_runtime_c__float__Sequence__fini(&msg->joint_torque);
  // wrench
  rosidl_runtime_c__float__Sequence__fini(&msg->wrench);
  // tcp_pose
  rosidl_runtime_c__float__Sequence__fini(&msg->tcp_pose);
  // tcp_twist
  rosidl_runtime_c__float__Sequence__fini(&msg->tcp_twist);
  // manipulability
  // singularity_distance
}

bool
armos_interfaces__msg__ArmosTelemetry__are_equal(const armos_interfaces__msg__ArmosTelemetry * lhs, const armos_interfaces__msg__ArmosTelemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // joint_pos
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_pos), &(rhs->joint_pos)))
  {
    return false;
  }
  // joint_vel
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_vel), &(rhs->joint_vel)))
  {
    return false;
  }
  // joint_torque
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->joint_torque), &(rhs->joint_torque)))
  {
    return false;
  }
  // wrench
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->wrench), &(rhs->wrench)))
  {
    return false;
  }
  // tcp_pose
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->tcp_pose), &(rhs->tcp_pose)))
  {
    return false;
  }
  // tcp_twist
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->tcp_twist), &(rhs->tcp_twist)))
  {
    return false;
  }
  // manipulability
  if (lhs->manipulability != rhs->manipulability) {
    return false;
  }
  // singularity_distance
  if (lhs->singularity_distance != rhs->singularity_distance) {
    return false;
  }
  return true;
}

bool
armos_interfaces__msg__ArmosTelemetry__copy(
  const armos_interfaces__msg__ArmosTelemetry * input,
  armos_interfaces__msg__ArmosTelemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // timestamp
  output->timestamp = input->timestamp;
  // joint_pos
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_pos), &(output->joint_pos)))
  {
    return false;
  }
  // joint_vel
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_vel), &(output->joint_vel)))
  {
    return false;
  }
  // joint_torque
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->joint_torque), &(output->joint_torque)))
  {
    return false;
  }
  // wrench
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->wrench), &(output->wrench)))
  {
    return false;
  }
  // tcp_pose
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->tcp_pose), &(output->tcp_pose)))
  {
    return false;
  }
  // tcp_twist
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->tcp_twist), &(output->tcp_twist)))
  {
    return false;
  }
  // manipulability
  output->manipulability = input->manipulability;
  // singularity_distance
  output->singularity_distance = input->singularity_distance;
  return true;
}

armos_interfaces__msg__ArmosTelemetry *
armos_interfaces__msg__ArmosTelemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosTelemetry * msg = (armos_interfaces__msg__ArmosTelemetry *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosTelemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(armos_interfaces__msg__ArmosTelemetry));
  bool success = armos_interfaces__msg__ArmosTelemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
armos_interfaces__msg__ArmosTelemetry__destroy(armos_interfaces__msg__ArmosTelemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    armos_interfaces__msg__ArmosTelemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
armos_interfaces__msg__ArmosTelemetry__Sequence__init(armos_interfaces__msg__ArmosTelemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosTelemetry * data = NULL;

  if (size) {
    data = (armos_interfaces__msg__ArmosTelemetry *)allocator.zero_allocate(size, sizeof(armos_interfaces__msg__ArmosTelemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = armos_interfaces__msg__ArmosTelemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        armos_interfaces__msg__ArmosTelemetry__fini(&data[i - 1]);
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
armos_interfaces__msg__ArmosTelemetry__Sequence__fini(armos_interfaces__msg__ArmosTelemetry__Sequence * array)
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
      armos_interfaces__msg__ArmosTelemetry__fini(&array->data[i]);
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

armos_interfaces__msg__ArmosTelemetry__Sequence *
armos_interfaces__msg__ArmosTelemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  armos_interfaces__msg__ArmosTelemetry__Sequence * array = (armos_interfaces__msg__ArmosTelemetry__Sequence *)allocator.allocate(sizeof(armos_interfaces__msg__ArmosTelemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = armos_interfaces__msg__ArmosTelemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
armos_interfaces__msg__ArmosTelemetry__Sequence__destroy(armos_interfaces__msg__ArmosTelemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    armos_interfaces__msg__ArmosTelemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
armos_interfaces__msg__ArmosTelemetry__Sequence__are_equal(const armos_interfaces__msg__ArmosTelemetry__Sequence * lhs, const armos_interfaces__msg__ArmosTelemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!armos_interfaces__msg__ArmosTelemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
armos_interfaces__msg__ArmosTelemetry__Sequence__copy(
  const armos_interfaces__msg__ArmosTelemetry__Sequence * input,
  armos_interfaces__msg__ArmosTelemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(armos_interfaces__msg__ArmosTelemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    armos_interfaces__msg__ArmosTelemetry * data =
      (armos_interfaces__msg__ArmosTelemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!armos_interfaces__msg__ArmosTelemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          armos_interfaces__msg__ArmosTelemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!armos_interfaces__msg__ArmosTelemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
