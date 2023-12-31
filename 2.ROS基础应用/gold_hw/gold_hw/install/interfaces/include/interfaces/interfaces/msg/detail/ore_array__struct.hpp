// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interfaces:msg/OreArray.idl
// generated code does not contain a copyright notice

#ifndef INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_HPP_
#define INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'ores'
#include "interfaces/msg/detail/ore_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__interfaces__msg__OreArray __attribute__((deprecated))
#else
# define DEPRECATED__interfaces__msg__OreArray __declspec(deprecated)
#endif

namespace interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OreArray_
{
  using Type = OreArray_<ContainerAllocator>;

  explicit OreArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit OreArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _ores_type =
    std::vector<interfaces::msg::OreInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::msg::OreInfo_<ContainerAllocator>>>;
  _ores_type ores;

  // setters for named parameter idiom
  Type & set__ores(
    const std::vector<interfaces::msg::OreInfo_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<interfaces::msg::OreInfo_<ContainerAllocator>>> & _arg)
  {
    this->ores = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interfaces::msg::OreArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const interfaces::msg::OreArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interfaces::msg::OreArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interfaces::msg::OreArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::OreArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::OreArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interfaces::msg::OreArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interfaces::msg::OreArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interfaces::msg::OreArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interfaces::msg::OreArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interfaces__msg__OreArray
    std::shared_ptr<interfaces::msg::OreArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interfaces__msg__OreArray
    std::shared_ptr<interfaces::msg::OreArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OreArray_ & other) const
  {
    if (this->ores != other.ores) {
      return false;
    }
    return true;
  }
  bool operator!=(const OreArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OreArray_

// alias to use template instance with default allocator
using OreArray =
  interfaces::msg::OreArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace interfaces

#endif  // INTERFACES__MSG__DETAIL__ORE_ARRAY__STRUCT_HPP_
