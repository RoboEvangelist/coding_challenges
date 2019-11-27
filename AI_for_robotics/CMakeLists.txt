cmake_minimum_required (VERSION 2.6)
project (robot_motion)
include_directories(include)
add_executable(robot robot_main.cpp src/robot.cpp)
