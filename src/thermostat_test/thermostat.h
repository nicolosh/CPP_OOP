#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <iostream>

class Thermostat
{
public:
  Thermostat(float temp, unsigned int status, const std::string &uom, const std::string &loc);
  ~Thermostat();
  void displayStatus(const std::string &desiredU);

  // getters (we need to validate our input data)
  float getTemp() { return temperature; };
  unsigned int getMode() { return mode; };
  std::string getLocation() { return location; };
  std::string getUoM() { return uom; };

  // setters
  void setTemp(float temperature);
  void setMode(unsigned int mode);
  void setLocation(const std::string &loc);
  void setUoM(const std::string &u);

private: // member variables
  static const unsigned int MIN_MODE = 0;
  static const unsigned int MAX_MODE = 2;
  static const unsigned int MAX_CHARS_LENGTH = 32;
  static const unsigned int FAR_OFFSET = MAX_CHARS_LENGTH;
  const float MIN_TEMP = -10.0;
  const float MAX_TEMP = 40.0;
  const float KELVIN_OFFSET = 273.15;
  const float FAR_CONST = 1.8;

  bool checkUoM(const std::string &u);
  float temperatureConverter(float temperature,
                             const std::string &desiredUoM) const;
  float temperature;
  unsigned int mode; // 0 (OFF), 1 (cooling) or 2 (heating)
  std::string uom;   // unit of measurement [C], [F], [K]
  std::string location;
};
#endif