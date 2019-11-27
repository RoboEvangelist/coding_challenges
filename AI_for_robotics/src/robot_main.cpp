#include "robot/robot.hpp"

int main(int argc, char** argv) {
  // Initializing 2D vector "vect" with 
  // values 
  std::vector<std::vector<float>> landmarks{{20.0, 20.0}, 
                                            {80.0, 80.0}, 
                                            {20.0, 80.0}, 
                                            {80.0, 20.0}};
  /// size in meters
  float world_size = 100.0;
  Robot robot(world_size);
  robot.set(10, 10, 0);

  return 0;
}

