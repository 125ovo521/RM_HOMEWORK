// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/OreArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_ARRAY__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__ORE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/ore_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_OreArray_ores
{
public:
  Init_OreArray_ores()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::msg::OreArray ores(::interfaces::msg::OreArray::_ores_type arg)
  {
    msg_.ores = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::OreArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::OreArray>()
{
  return interfaces::msg::builder::Init_OreArray_ores();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ORE_ARRAY__BUILDER_HPP_
