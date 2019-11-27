#ifndef ROBOT_HPP
#define	ROBOT_HPP

#include <string>
#include <vector>
#include <algorithm>
#include <math>
#include <random>
#include <cstdlib>
#include <iostream>


class Robot
{
 public:
  Robot() 
  {
  }
  
  ~Robot() {}
  
  /// @brief Load trained model for face detection
  /// @param graph_path path to trained face model save
  /// @param session used to run the graph and produce the output
  /// @return whether face is loaded or not
  int LoadFaceDetectModel(const std::string graph_path);
    
 private:
  int x_location_;
  int y_location_;
  float orientation_;

};

#endif  // ROBOT_HPP

