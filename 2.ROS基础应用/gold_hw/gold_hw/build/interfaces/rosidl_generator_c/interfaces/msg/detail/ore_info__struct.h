// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/OreInfo.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_INFO__STRUCT_H_
#define INTERFACES__MSG__DETAIL__ORE_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
#include "rosidl_runtime_c/string.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/OreInfo in the package interfaces.
typedef struct interfaces__msg__OreInfo
{
  int64_t num;
  rosidl_runtime_c__String type;
  geometry_msgs__msg__Point position;
  double value;
} interfaces__msg__OreInfo;

// Struct for a sequence of interfaces__msg__OreInfo.
typedef struct interfaces__msg__OreInfo__Sequence
{
  interfaces__msg__OreInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__OreInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__ORE_INFO__STRUCT_H_
