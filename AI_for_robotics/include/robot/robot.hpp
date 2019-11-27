#ifndef ROBOT_HPP
#define	ROBOT_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <cstdlib>
#include <iostream>


class Robot
{
 public:
  /// world size is in meters
  Robot(float world_size=100.0) : forward_noise_(0.0), turn_noise_(0.0),
  sense_noise_(0.0) {
  /// the initial random numbers fall in the range [0, 1.0] inclusive
  x_location_ =
    (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * world_size;
  y_location_ =
    (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * world_size;
  orientation_ =
    (static_cast<float>(rand()) / static_cast<float>(RAND_MAX)) * 2.0 * M_PI;
  }
  
  ~Robot() {}
  
  /// @brief Set robot's pose
  /// @param x
  /// @param y
  /// @param orient
  /// @return void
  void set(float x, float y, float orient);

  /// @brief Makes robot move
  /// @param orient
  /// @param distance distance in meters
  /// @return void
  void move(float orient, float distance);
    
 private:
  float x_location_;
  float y_location_;
  float orientation_;
  float forward_noise_;
  float turn_noise_;
  float sense_noise_;

};

#endif  // ROBOT_HPP

