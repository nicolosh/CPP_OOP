#include "thermostat.h"
#define LOCATION "Living Room"

int main()
{
  Thermostat thermo(27, 1, "F", LOCATION);
  thermo.displayStatus("F");

  thermo.setLocation("Bedroom");
  thermo.setMode(2);
  thermo.setUoM("C");
  thermo.setTemp(33.5);
  thermo.displayStatus("F");
  return 0;
}