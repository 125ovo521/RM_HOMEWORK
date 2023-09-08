// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:msg/OreInfo.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_INFO__BUILDER_HPP_
#define INTERFACES__MSG__DETAIL__ORE_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/msg/detail/ore_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace msg
{

namespace builder
{

class Init_OreInfo_value
{
public:
  explicit Init_OreInfo_value(::interfaces::msg::OreInfo & msg)
  : msg_(msg)
  {}
  ::interfaces::msg::OreInfo value(::interfaces::msg::OreInfo::_value_type arg)
  {
    msg_.value = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::msg::OreInfo msg_;
};

class Init_OreInfo_position
{
public:
  explicit Init_OreInfo_position(::interfaces::msg::OreInfo & msg)
  : msg_(msg)
  {}
  Init_OreInfo_value position(::interfaces::msg::OreInfo::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_OreInfo_value(msg_);
  }

private:
  ::interfaces::msg::OreInfo msg_;
};

class Init_OreInfo_type
{
public:
  explicit Init_OreInfo_type(::interfaces::msg::OreInfo & msg)
  : msg_(msg)
  {}
  Init_OreInfo_position type(::interfaces::msg::OreInfo::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_OreInfo_position(msg_);
  }

private:
  ::interfaces::msg::OreInfo msg_;
};

class Init_OreInfo_num
{
public:
  Init_OreInfo_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OreInfo_type num(::interfaces::msg::OreInfo::_num_type arg)
  {
    msg_.num = std::move(arg);
    return Init_OreInfo_type(msg_);
  }

private:
  ::interfaces::msg::OreInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::msg::OreInfo>()
{
  return interfaces::msg::builder::Init_OreInfo_num();
}

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ORE_INFO__BUILDER_HPP_
