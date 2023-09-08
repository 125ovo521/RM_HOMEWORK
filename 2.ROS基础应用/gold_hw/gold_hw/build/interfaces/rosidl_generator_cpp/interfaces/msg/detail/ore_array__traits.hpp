// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:msg/OreArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_ARRAY__TRAITS_HPP_
#define INTERFACES__MSG__DETAIL__ORE_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/msg/detail/ore_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'ores'
#include "interfaces/msg/detail/ore_info__traits.hpp"

namespace interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const OreArray & msg,
  std::ostream & out)
{
  out << "{";
  // member: ores
  {
    if (msg.ores.size() == 0) {
      out << "ores: []";
    } else {
      out << "ores: [";
      size_t pending_items = msg.ores.size();
      for (auto item : msg.ores) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OreArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ores
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ores.size() == 0) {
      out << "ores: []\n";
    } else {
      out << "ores:\n";
      for (auto item : msg.ores) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OreArray & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::msg::OreArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::msg::OreArray & msg)
{
  return interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::msg::OreArray>()
{
  return "interfaces::msg::OreArray";
}

template<>
inline const char * name<interfaces::msg::OreArray>()
{
  return "interfaces/msg/OreArray";
}

template<>
struct has_fixed_size<interfaces::msg::OreArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<interfaces::msg::OreArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<interfaces::msg::OreArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__MSG__DETAIL__ORE_ARRAY__TRAITS_HPP_
