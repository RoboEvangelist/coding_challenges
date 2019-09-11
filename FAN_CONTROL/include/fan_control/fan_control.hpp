/* fan_control.hpp
   Copyright 2019 Luis Bill
*/

#include <cmath>

#ifndef FAN_HPP
#define FAN_HPP

class Fan {
 public:
  explicit Fan(uint8_t& fan_register) : fan_register_(fan_register),
    duty_cycle_(0), speed_(0) {}
  ~Fan() {
    /// turn fan off
    speed_ = 0;
    duty_cycle_ = 0;
  }
  uint8_t getFanRegister() const {return fan_register_;}
  uint32_t getSpeed() const {return speed_;}
  uint32_t getDutyCycle() const {return duty_cycle_;}
  void setSpeed(uint32_t speed) {speed_ = speed;}
  void setDutyCycle(uint32_t duty_cycle) {duty_cycle_ = duty_cycle;}

 private:
  /// fan registed (like the fan's ID)
  uint8_t fan_register_;
  /// duty cycle in percentage
  uint8_t duty_cycle_;
  /// fan speed
  uint32_t speed_;
};
#endif  // "FAN_HPP"

