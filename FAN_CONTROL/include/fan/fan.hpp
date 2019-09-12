/* fan.hpp
   Copyright 2019 Luis Bill
*/

#include <cmath>
#include <iostream>

#ifndef FAN_HPP
#define FAN_HPP

class Fan {
 public:
  explicit Fan(uint8_t& fan_register) : fan_register_(fan_register),
    duty_cycle_(0), register_value_(0) {}
  ~Fan() {
    /// turn fan off
    register_value_ = 0;
    duty_cycle_ = 0;
  }
  uint8_t getFanRegister() const {return fan_register_;}
  uint32_t getRegisterValue() const {return register_value_;}
  uint32_t getDutyCycle() const {return duty_cycle_;}
  uint32_t getTemperatureCelcius() const {return temperature_;}
  void setDutyCycle(uint32_t duty_cycle) {duty_cycle_ = duty_cycle;}
  void setSpeedToRegister(uint32_t speed) {register_value_ = speed;}
  void readTemperature(uint32_t temperature);

 private:
  /// fan registed (like the fan's ID)
  uint8_t fan_register_;
  /// duty cycle in percentage
  uint8_t duty_cycle_;
  /// fan speed is set by sending this number to the register
  uint32_t register_value_;
  /// temperature of the system the fan is cooling off
  uint32_t temperature_;
};
#endif  // "FAN_HPP"

