// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from interfaces:srv/OrePosition.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ORE_POSITION__TRAITS_HPP_
#define INTERFACES__SRV__DETAIL__ORE_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "interfaces/srv/detail/ore_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrePosition_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrePosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrePosition_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::OrePosition_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::OrePosition_Request & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::OrePosition_Request>()
{
  return "interfaces::srv::OrePosition_Request";
}

template<>
inline const char * name<interfaces::srv::OrePosition_Request>()
{
  return "interfaces/srv/OrePosition_Request";
}

template<>
struct has_fixed_size<interfaces::srv::OrePosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<interfaces::srv::OrePosition_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<interfaces::srv::OrePosition_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const OrePosition_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: position
  {
    out << "position: ";
    to_flow_style_yaml(msg.position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OrePosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position:\n";
    to_block_style_yaml(msg.position, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OrePosition_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace interfaces

namespace rosidl_generator_traits
{

[[deprecated("use interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const interfaces::srv::OrePosition_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const interfaces::srv::OrePosition_Response & msg)
{
  return interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<interfaces::srv::OrePosition_Response>()
{
  return "interfaces::srv::OrePosition_Response";
}

template<>
inline const char * name<interfaces::srv::OrePosition_Response>()
{
  return "interfaces/srv/OrePosition_Response";
}

template<>
struct has_fixed_size<interfaces::srv::OrePosition_Response>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<interfaces::srv::OrePosition_Response>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<interfaces::srv::OrePosition_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<interfaces::srv::OrePosition>()
{
  return "interfaces::srv::OrePosition";
}

template<>
inline const char * name<interfaces::srv::OrePosition>()
{
  return "interfaces/srv/OrePosition";
}

template<>
struct has_fixed_size<interfaces::srv::OrePosition>
  : std::integral_constant<
    bool,
    has_fixed_size<interfaces::srv::OrePosition_Request>::value &&
    has_fixed_size<interfaces::srv::OrePosition_Response>::value
  >
{
};

template<>
struct has_bounded_size<interfaces::srv::OrePosition>
  : std::integral_constant<
    bool,
    has_bounded_size<interfaces::srv::OrePosition_Request>::value &&
    has_bounded_size<interfaces::srv::OrePosition_Response>::value
  >
{
};

template<>
struct is_service<interfaces::srv::OrePosition>
  : std::true_type
{
};

template<>
struct is_service_request<interfaces::srv::OrePosition_Request>
  : std::true_type
{
};

template<>
struct is_service_response<interfaces::srv::OrePosition_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // INTERFACES__SRV__DETAIL__ORE_POSITION__TRAITS_HPP_
