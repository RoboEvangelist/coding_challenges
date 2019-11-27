#include "robot/robot.hpp"

void Robot::set(float x, float y, float orient) {
  x_location_ = x;
  y_location_ = y;
  orientation_ = orient;
  std::cout << "x=" << x_location_ << " ";
  std::cout << "y=" << y_location_ << " ";
  std::cout << "orient=" << orientation_ << "\n\n";
}

