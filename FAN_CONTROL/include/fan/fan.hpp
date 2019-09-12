/* fan.hpp
   Copyright 2019 Luis Bill
*/

#include <cstdint>

#ifndef FAN_HPP
#define FAN_HPP

class Fan {
 public:
  /* @brief constructor initializes the fan's register
     @param fan_register is the register associated with the fan 
     @return void
  */
  explicit Fan(uint8_t& fan_register) : fan_register_(fan_register),
    duty_cycle_(0), register_value_(0) {}
  /* @brief distructor turns off the fan
     @return void
  */
  ~Fan() {
    /// turn fan off
    register_value_ = 0;
    duty_cycle_ = 0;
  }
  /* @brief function that returns the register the fan is connected to
     @return the fan_register_ value
  */
  uint8_t getFanRegister() const {return fan_register_;}
  /* @brief function that returns the last value sent to the
     @return las value sent to the register
  */
  uint32_t getRegisterValue() const {return register_value_;}
  /* @brief function returns the last measured temperature of
            the system associated with this fan
     @return last measured temperature
  */
  float getTemperature() const {return temperature_;}
  /* @brief function that gets the las duty cycle state of fan
     @return duty cycle value
  */
  float getDutyCycle() const {return duty_cycle_;}
  /* @brief has a input the temperature of the system, and then
            uses this temperature value to set the fan's duty
            cycle
     @param temperature current temperature of the system 
     @return void
  */
  void readTemperature(float temperature);

 private:
  /// fan registed (like the fan's ID)
  uint8_t fan_register_;
  /// fan speed is set by sending this number to the register hardware
  /// register connected to the fan
  volatile uint32_t register_value_;
  /// duty cycle in percentage
  float duty_cycle_;
  /// temperature of the system the fan is cooling off
  float temperature_;
};
#endif  // "FAN_HPP"

