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

  std::vector<float> kalman_update =
    kalman_filter.kalman_update(10, 8, 13, 2);
  for (const auto update : kalman_update)
    std::cout << update << ", ";
  std::cout << "\n";

  return 0;
}

