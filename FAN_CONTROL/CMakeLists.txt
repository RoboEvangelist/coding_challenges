cmake_minimum_required (VERSION 2.6)
project (fan_control)
include_directories(include)
add_executable(fan_control fan_control_main.cpp fan.cpp)
