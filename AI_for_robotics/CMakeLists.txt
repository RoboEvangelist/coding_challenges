cmake_minimum_required (VERSION 2.6)
project (robot_motion)
include_directories(include)
add_executable(robot src/robot_main.cpp src/robot.cpp src/kalman_filter.cpp)
