#ifndef KALMAN_FILTER_HPP
#define	KALMAN_FILTER_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <cstdlib>
#include <iostream>

class KalmanFilter {
 public:
  /// world size is in meters
  KalmanFilter() {}
  
  ~KalmanFilter() {}

  /// @brief update method for the kalman filter
  /// @return returns new mean and variances
  std::vector<float> kalman_update(float mean1, float var1,
    float mean2, float var2);

  /// @brief update method for the kalman filter
  /// @return returns new mean and variances
  std::vector<float> kalman_predict(float mean1, float var1,
    float mean2, float var2);
};

#endif  // KALMAN_FILTER_HPP

