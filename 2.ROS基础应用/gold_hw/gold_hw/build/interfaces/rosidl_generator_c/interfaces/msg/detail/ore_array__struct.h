// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interfaces:msg/OreArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_H_
#define INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ores'
#include "interfaces/msg/detail/ore_info__struct.h"

/// Struct defined in msg/OreArray in the package interfaces.
typedef struct interfaces__msg__OreArray
{
  interfaces__msg__OreInfo__Sequence ores;
} interfaces__msg__OreArray;

// Struct for a sequence of interfaces__msg__OreArray.
typedef struct interfaces__msg__OreArray__Sequence
{
  interfaces__msg__OreArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interfaces__msg__OreArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_H_
