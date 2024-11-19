#include <iostream>
#include <string>
using namespace std;

class Thermostat
{
public:
  // Constructor to initialize the thermostat
  Thermostat(float temp, unsigned int m, const string &loc)
  {
    temperature = temp;
    mode = m;
    location = loc;
  }

  // Destructor
  ~Thermostat()
  {
    cout << "Thermostat in " << location << " is being destroyed." << endl;
  }

  // Member function to display current status of the thermostat
  void displayStatus()
  {
    cout << "Location: " << location << " Temperature: " << temperature << "°C Mode: " << (mode == 0 ? "OFF " : (mode == 1 ? "COOLING " : "HEATING ")) << endl;
  }

private:
  float temperature; // Temperature in degrees Celsius
  unsigned int mode; // Mode (0 for OFF, 1 for COOLING, 2 for HEATING)
  string location;   // Location of the thermostat
};

int main()
{
  // Create a Thermostat object
  Thermostat livingRoomThermostat(22.5, 1, "Living Room");

  // Display the status of the thermostat
  livingRoomThermostat.displayStatus();

  return 0;
}