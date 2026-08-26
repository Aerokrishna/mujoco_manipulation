// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from armos_interfaces:msg/ArmosTelemetry.idl
// generated code does not contain a copyright notice
#include "armos_interfaces/msg/detail/armos_telemetry__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "armos_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "armos_interfaces/msg/detail/armos_telemetry__struct.h"
#include "armos_interfaces/msg/detail/armos_telemetry__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // joint_pos, joint_torque, joint_vel, tcp_pose, tcp_twist, wrench
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // joint_pos, joint_torque, joint_vel, tcp_pose, tcp_twist, wrench

// forward declare type support functions


using _ArmosTelemetry__ros_msg_type = armos_interfaces__msg__ArmosTelemetry;

static bool _ArmosTelemetry__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ArmosTelemetry__ros_msg_type * ros_message = static_cast<const _ArmosTelemetry__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: joint_pos
  {
    size_t size = ros_message->joint_pos.size;
    auto array_ptr = ros_message->joint_pos.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_vel
  {
    size_t size = ros_message->joint_vel.size;
    auto array_ptr = ros_message->joint_vel.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: joint_torque
  {
    size_t size = ros_message->joint_torque.size;
    auto array_ptr = ros_message->joint_torque.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: wrench
  {
    size_t size = ros_message->wrench.size;
    auto array_ptr = ros_message->wrench.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tcp_pose
  {
    size_t size = ros_message->tcp_pose.size;
    auto array_ptr = ros_message->tcp_pose.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: tcp_twist
  {
    size_t size = ros_message->tcp_twist.size;
    auto array_ptr = ros_message->tcp_twist.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: manipulability
  {
    cdr << ros_message->manipulability;
  }

  // Field name: singularity_distance
  {
    cdr << ros_message->singularity_distance;
  }

  return true;
}

static bool _ArmosTelemetry__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ArmosTelemetry__ros_msg_type * ros_message = static_cast<_ArmosTelemetry__ros_msg_type *>(untyped_ros_message);
  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  // Field name: joint_pos
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_pos.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_pos);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_pos, size)) {
      fprintf(stderr, "failed to create array for field 'joint_pos'");
      return false;
    }
    auto array_ptr = ros_message->joint_pos.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_vel
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_vel.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_vel);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_vel, size)) {
      fprintf(stderr, "failed to create array for field 'joint_vel'");
      return false;
    }
    auto array_ptr = ros_message->joint_vel.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: joint_torque
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->joint_torque.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->joint_torque);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->joint_torque, size)) {
      fprintf(stderr, "failed to create array for field 'joint_torque'");
      return false;
    }
    auto array_ptr = ros_message->joint_torque.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: wrench
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->wrench.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->wrench);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->wrench, size)) {
      fprintf(stderr, "failed to create array for field 'wrench'");
      return false;
    }
    auto array_ptr = ros_message->wrench.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tcp_pose
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->tcp_pose.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->tcp_pose);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->tcp_pose, size)) {
      fprintf(stderr, "failed to create array for field 'tcp_pose'");
      return false;
    }
    auto array_ptr = ros_message->tcp_pose.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: tcp_twist
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->tcp_twist.data) {
      rosidl_runtime_c__float__Sequence__fini(&ros_message->tcp_twist);
    }
    if (!rosidl_runtime_c__float__Sequence__init(&ros_message->tcp_twist, size)) {
      fprintf(stderr, "failed to create array for field 'tcp_twist'");
      return false;
    }
    auto array_ptr = ros_message->tcp_twist.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: manipulability
  {
    cdr >> ros_message->manipulability;
  }

  // Field name: singularity_distance
  {
    cdr >> ros_message->singularity_distance;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armos_interfaces
size_t get_serialized_size_armos_interfaces__msg__ArmosTelemetry(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ArmosTelemetry__ros_msg_type * ros_message = static_cast<const _ArmosTelemetry__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_pos
  {
    size_t array_size = ros_message->joint_pos.size;
    auto array_ptr = ros_message->joint_pos.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_vel
  {
    size_t array_size = ros_message->joint_vel.size;
    auto array_ptr = ros_message->joint_vel.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name joint_torque
  {
    size_t array_size = ros_message->joint_torque.size;
    auto array_ptr = ros_message->joint_torque.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name wrench
  {
    size_t array_size = ros_message->wrench.size;
    auto array_ptr = ros_message->wrench.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tcp_pose
  {
    size_t array_size = ros_message->tcp_pose.size;
    auto array_ptr = ros_message->tcp_pose.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tcp_twist
  {
    size_t array_size = ros_message->tcp_twist.size;
    auto array_ptr = ros_message->tcp_twist.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name manipulability
  {
    size_t item_size = sizeof(ros_message->manipulability);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name singularity_distance
  {
    size_t item_size = sizeof(ros_message->singularity_distance);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ArmosTelemetry__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_armos_interfaces__msg__ArmosTelemetry(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_armos_interfaces
size_t max_serialized_size_armos_interfaces__msg__ArmosTelemetry(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: timestamp
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_pos
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_vel
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: joint_torque
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: wrench
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tcp_pose
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: tcp_twist
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: manipulability
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: singularity_distance
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = armos_interfaces__msg__ArmosTelemetry;
    is_plain =
      (
      offsetof(DataType, singularity_distance) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _ArmosTelemetry__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_armos_interfaces__msg__ArmosTelemetry(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_ArmosTelemetry = {
  "armos_interfaces::msg",
  "ArmosTelemetry",
  _ArmosTelemetry__cdr_serialize,
  _ArmosTelemetry__cdr_deserialize,
  _ArmosTelemetry__get_serialized_size,
  _ArmosTelemetry__max_serialized_size
};

static rosidl_message_type_support_t _ArmosTelemetry__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ArmosTelemetry,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, armos_interfaces, msg, ArmosTelemetry)() {
  return &_ArmosTelemetry__type_support;
}

#if defined(__cplusplus)
}
#endif
