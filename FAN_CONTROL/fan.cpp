/* fan.cpp
   Copyright 2019 Luis Bill
*/

#include <climits>
#include "fan/fan.hpp"

void Fan::readTemperature(uint32_t temperature) {
  temperature_ = temperature;
  /*
  The fan control algorithm should behave as follows:
  If the temperature is 25° C or below, the fans should run at 20% duty cycle.
If the temperature is 75° C or above, the fans should run at 100% duty cycle.
  If the maximum measured subsystem temperature is in between 25° and 75° C,
  the fans should run at a duty cycle linearly interpolated between 20% and 100% duty cycle.
  */

  if (temperature_ <= 25)
    duty_cycle_ = 20;
  else if (temperature_ >= 75)
    duty_cycle_ = 100;
  /// linearly interpolate
  /// we are trying to convert the range (25, 75) into (20, 100)
  else if ((temperature_ > 25) || (temperature_ < 75)) {
    duty_cycle_ = (((temperature_ - 26) * (99 - 21)) / (74 - 26)) + 21;
  }

  /// We are told that the register value is proportional to
  /// the duty cycle. Therefore:
  
  register_value_ = (UINT_MAX / 100) * duty_cycle_;
}

