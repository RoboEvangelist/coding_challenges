/* fan_control_main.cpp
   Copyright 2019 Luis Bill
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <algorithm>

#include "fan/fan.hpp"

int main() {
  /// random seed using the clock
  srand(time(NULL));
  /// we asume each system has one fan
  uint8_t num_systems = 10;
  /// fans shall not work if there's nothing to cool off
  if (num_systems <= 0)
    return 0;
  float max_temperature = 0;
  /// unordered map allows us to have unique ID's for the
  /// registeres
  std::vector<Fan> system_vect;
  /// Let's associate each fan with a register
  /// the register number is the same as the fan number
  for (uint8_t i = 0; i < num_systems; ++i) {
    system_vect.push_back(Fan(i));
  }
  /// let's read random temperatures between 0 and 100 celcius
  /// the number of readings is the same as the number of
  /// systems/fans
  float limit = 100.0;
  for (int i = 0; i < num_systems; ++i) {
    float current_sys_temperature = static_cast <float>(rand()) /
      (static_cast <float>(RAND_MAX / limit));
    std::cout << "System " << i << "'s temperature is "
      << current_sys_temperature << " Celsius\n";
    max_temperature =
      std::max(max_temperature, current_sys_temperature);
  }
  std::cout << "\nMax Temperature reading is: " <<
    max_temperature << "\n\n";
  /// we use the max temperature to set the same duty cycle on each
  /// fan
  for (auto& fan : system_vect) {
    fan.readTemperature(max_temperature);
    std::cout << "Fan " << static_cast<int>(fan.getFanRegister())
      << " was set to a " << "duty cycle of "
      << fan.getDutyCycle() << "\n";
  }
  return 0;
}

