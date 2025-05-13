#include "warrior.h"

using namespace std;

int main()
{
  Character paperino("paperino", 110, "equipping");
  paperino.displayStatus();
  std::cout << std::endl;
  paperino.setCharacterName("pluto");
  paperino.setHealth(10);
  paperino.displayStatus();

  std::cout << std::endl;

  Equipment equipment;
  equipment.addItem("knife");
  equipment.addItem("Fork");
  equipment.addItem("gun");
  equipment.displayInventory();

  std::cout << std::endl;
  Warrior warrior = Warrior("Ridge", 100, 2000, 3000, 350, "attack");
  warrior.addItem("sword");
  warrior.addItem("Gun");
  warrior.displayStatus();
  return 0;
}