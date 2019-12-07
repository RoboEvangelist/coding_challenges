#include <cassert>
#include <chrono>
#include <iomanip>
#include <bits/stdc++.h>

#include "robot/robot.hpp"
#include "robot/kalman_filter.hpp"

int main(int argc, char** argv) {
  // Initializing 2D vector "vect" with 
  // values 
  std::vector<std::vector<float>> landmarks{{20.0, 20.0}, 
                                            {80.0, 80.0}, 
                                            {20.0, 80.0}, 
                                            {80.0, 20.0}};
  /// size in meters
  float world_size = 100.0;
  Robot robot(world_size, landmarks);
  KalmanFilter kalman_filter;
  robot.set(10, 10, 0);
  robot.move(M_PI/2, 10);
  std::vector<float> measurements = robot.sense();
  for (const auto measurement : measurements)
    std::cout << measurement << ", ";
  std::cout << "\n";

  /// Kalman Filter
  std::vector<float> kal_measurements = {5.0, 6.0, 7.0, 9.0, 10.0};
  std::vector<float> motion = {1.0, 1.0, 2.0, 1.0, 1.0};

  uint8_t motion_size = motion.size();

  assert(kal_measurements.size() == motion_size);
  
  /// measurement uncertainty
  constexpr float measurement_sig = 4;
  /// motion uncertainty
  constexpr float motion_sig = 2;
  /// initial estimante. Basically the middle of the bell
  float mu = 0;
  /// uncertainty. How spread the curve is
  float sig = 1000;

//  auto start = std::chrono::high_resolution_clock::now(); 
  // unsync the I/O of C and C++. 
//  std::ios_base::sync_with_stdio(false);

  /// position estimate
  for (uint8_t i = 0; i < motion_size; ++i) {
    std::vector<float> kalman_values =
    kalman_filter.kalman_update(mu, sig, kal_measurements.at(i),
      measurement_sig);
    mu = std::move(kalman_values.at(0));
    sig = std::move(kalman_values.at(1));
    std::cout << "update: " << "[" << mu << ", " << sig << "]\n";
    kalman_values =
    kalman_filter.kalman_predict(mu, sig, motion.at(i), motion_sig);
    mu = std::move(kalman_values.at(0));
    sig = std::move(kalman_values.at(1));
    std::cout << "predict " << "[" << mu << ", " << sig << "]\n";
  }
//  auto end = std::chrono::high_resolution_clock::now(); 
//  // Calculating total time taken by the program. 
//  double time_taken =  
//    std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(); 
//  
//  time_taken *= 1e-9; 
//  
//  std::cout << "Time taken by program is : " << std::fixed  
//       << time_taken << std::setprecision(20); 
//  std::cout << " sec" << std::endl;

  return 0;
}

