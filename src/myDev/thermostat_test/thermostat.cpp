#include "thermostat.h"

Thermostat::Thermostat(float temp, unsigned int status, const std::string &uom, const std::string &loc)
{
  setTemp(temp);
  setMode(status);
  setUoM(uom);
  setLocation(loc);
}

Thermostat::~Thermostat()
{
  std::cout << "The thermostat placed in the location " << location << " is being deleted; " << std::endl;
}

void Thermostat::displayStatus(const std::string &desiredU)
{
  std::cout << "Temperature [° " << uom << "]: " << temperature << " [° " << uom << "]\nMode: " << (mode == 0 ? "OFF" : (mode == 1 ? "COOLING" : "HEATING")) << "\nLocation: " << location << std::endl;
  if (!checkUoM(desiredU))
    throw std::invalid_argument("The inserted thermostat unit of measurement (°" + desiredU + ") is not valid. It must be K, F, or C");

  temperature = temperatureConverter(temperature, desiredU);
  if (uom != desiredU)
    std::cout << "Temperature in the new unit of measurement inserted ([° " << desiredU << "]) is: " << temperature << " [° " << desiredU << "]" << std::endl;
}

void Thermostat::setTemp(float temperature)
{
  if (!(temperature >= MIN_TEMP && temperature <= MAX_TEMP))
    throw std::invalid_argument("The thermostat temperature inserted (" + std::to_string(temperature) + ") must be between " + std::to_string(MIN_TEMP) + " and " + std::to_string(MAX_TEMP));

  this->temperature = temperature;
}

void Thermostat::setMode(unsigned int mode)
{
  if (!(mode >= MIN_MODE && mode <= MAX_MODE))
    throw std::invalid_argument("The thermostat mode inserted (" + std::to_string(mode) + ") must be between " + std::to_string(MIN_MODE) + " and " + std::to_string(MAX_MODE));

  this->mode = mode;
}

bool Thermostat::checkUoM(const std::string &u)
{
  if (!(u == "F" || u == "C" || u == "K"))
    return false;
  return true;
}

void Thermostat::setUoM(const std::string &u)
{
  if (checkUoM(u) == false)
    throw std::invalid_argument("The inserted thermostat unit of measurement (°" + u + ") is not valid. It must be K, F, or C");
  uom = u;
}

void Thermostat::setLocation(const std::string &loc)
{
  if (loc.empty())
    throw std::invalid_argument("The input location " + loc + " is not valid. Thermostat cannot read more than " + std::to_string(MAX_CHARS_LENGTH) + " characters or be empty");

  location = loc.length() > MAX_CHARS_LENGTH ? loc.substr(0, MAX_CHARS_LENGTH) : loc;
}

float Thermostat::temperatureConverter(float temperature, const std::string &desiredUoM) const
{
  // if I am here desiredUoM has already been validated
  if (uom == "F" && desiredUoM == "K")
    return (temperature - FAR_OFFSET) / FAR_CONST + KELVIN_OFFSET;
  else if (uom == "K" && desiredUoM == "F")
    return (temperature - KELVIN_OFFSET) * FAR_CONST + FAR_OFFSET;

  else if (uom == "C" && desiredUoM == "K")
    return temperature + KELVIN_OFFSET;
  else if (uom == "K" && desiredUoM == "C")
    return temperature - KELVIN_OFFSET;

  else if (uom == "F" && desiredUoM == "C")
    return (temperature - FAR_OFFSET) / FAR_CONST;
  else if (uom == "C" && desiredUoM == "F")
    return FAR_CONST * temperature + FAR_OFFSET;

  return temperature;
}