#include "robot/kalman_filter.hpp"

std::vector<float> KalmanFilter::kalman_update(float mean1, float var1,
  float mean2, float var2) {
  float new_mean = (var2 * mean1 + var1 * mean2) / (var1 + var2);
  float new_var = 1.0 / ((1.0 / var1) + (1.0 / var2));
  return {new_mean, new_var};
}

std::vector<float> KalmanFilter::kalman_predict(float mean1, float var1,
  float mean2, float var2) {
  float new_mean = (var2 * mean1 + var1 * mean2) / (var1 + var2);
  float new_var = 1.0 / ((1.0 / var1) + (1.0 / var2));
  return {new_mean, new_var};
}
