#include "character.h"
#include "equipment.h"

using namespace std;

int main()
{
  Character paperino("paperino", 110, "defending");
  paperino.displayStatus();
  paperino.actionIsDoing();
  paperino.setCharacterName("pluto");
  paperino.setPoints(10);
  paperino.displayStatus();
  
  std::cout << std::endl;

  Equipment equipment;
  equipment.addItem("knife");
  equipment.addItem("Fork");
  equipment.addItem("gun");
  equipment.displayInventory();
  return 0;
}