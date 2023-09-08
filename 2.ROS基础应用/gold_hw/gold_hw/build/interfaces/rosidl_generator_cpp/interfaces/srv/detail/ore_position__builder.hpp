// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from interfaces:srv/OrePosition.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__SRV__DETAIL__ORE_POSITION__BUILDER_HPP_
#define INTERFACES__SRV__DETAIL__ORE_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "interfaces/srv/detail/ore_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_OrePosition_Request_id
{
public:
  Init_OrePosition_Request_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::OrePosition_Request id(::interfaces::srv::OrePosition_Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::OrePosition_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::OrePosition_Request>()
{
  return interfaces::srv::builder::Init_OrePosition_Request_id();
}

}  // namespace interfaces


namespace interfaces
{

namespace srv
{

namespace builder
{

class Init_OrePosition_Response_position
{
public:
  Init_OrePosition_Response_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::interfaces::srv::OrePosition_Response position(::interfaces::srv::OrePosition_Response::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::interfaces::srv::OrePosition_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::interfaces::srv::OrePosition_Response>()
{
  return interfaces::srv::builder::Init_OrePosition_Response_position();
}

}  // namespace interfaces

#endif  // INTERFACES__SRV__DETAIL__ORE_POSITION__BUILDER_HPP_
