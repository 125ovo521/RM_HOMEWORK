# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_gold_miner_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED gold_miner_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(gold_miner_FOUND FALSE)
  elseif(NOT gold_miner_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(gold_miner_FOUND FALSE)
  endif()
  return()
endif()
set(_gold_miner_CONFIG_INCLUDED TRUE)

# output package information
if(NOT gold_miner_FIND_QUIETLY)
  message(STATUS "Found gold_miner: 0.0.0 (${gold_miner_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'gold_miner' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${gold_miner_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(gold_miner_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${gold_miner_DIR}/${_extra}")
endforeach()
