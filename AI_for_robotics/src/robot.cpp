#include "robot/robot.hpp"

void Robot::set(float new_x, float new_y, float new_orient) {
  if ((new_x < 0) || (new_x >= world_size_))
    return;
  if ((new_y < 0) || (new_y >= world_size_))
    return;
  if ((new_orient < 0) || (new_orient >= (2 * M_PI)))
    return;
  x_location_ = new_x;
  y_location_ = new_y;
  orientation_ = new_orient;
  std::cout << "x=" << x_location_ << " ";
  std::cout << "y=" << y_location_ << " ";
  std::cout << "orient=" << orientation_ << "\n\n";
}

void Robot::set_noise(float new_f_noise, float new_t_noise, float new_s_noise) {
  forward_noise_ = new_f_noise;
  turn_noise_ = new_t_noise;
  sense_noise_ = new_s_noise;
}

void Robot::move(float orient, float distance) {
  std::cout << "x=" << x_location_ << " ";
  std::cout << "y=" << y_location_ << " ";
  std::cout << "orient=" << orientation_ << "\n\n";
}

std::vector<float> Robot::sense() {
  float dist;
  /// Z is the vector of measurements
  std::vector<float> Z;
  int landmarks_size = landmarks_.size();
  for (int i = 0; i < landmarks_size; ++i) {
    dist = sqrtf((x_location_ - landmarks_[i][0]));
  }
  return Z;
}

