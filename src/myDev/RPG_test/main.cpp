#include "fight_simulation.h"
#include <cstdlib> // For random numbers
#include <ctime>   // For seeding random numbers
// using namespace std;

int main()
{
  Character paperino("paperino", 94);
  paperino.displayStatus();

  std::cout << std::endl;

  paperino.setCharName("pluto");
  paperino.updateCharHealth(10);
  paperino.displayStatus();

  std::cout << std::endl;

  Equipment equipment;
  equipment.addItem("knife");
  equipment.addItem("Fork");
  equipment.addItem("knife");
  equipment.addItem("knife");
  equipment.addItem("gun");
  equipment.addItem("pan");
  equipment.displayInventory();

  std::cout << "Creating the warriors for 2 teams\n";
  Warrior Ridge = Warrior("Ridge", 100, 200, 300, 35, 2);
  Ridge.addItem("sword");
  Ridge.addItem("Beretta");
  Ridge.addItem("AK-47");
  Ridge.addItem("AK-47");
  Ridge.addItem("Molotov");
  // Ridge.displayStatus();

  Warrior Erik = Warrior("Erik", 100, 250, 340, 15, 1);
  Erik.addItem("ENMA");
  Erik.addItem("Beretta");
  Erik.addItem("Bazooka");
  Erik.addItem("Helicopter");
  // Erik.displayStatus();

  Warrior Thomas = Warrior("Thomas", 100, 210, 130, 24, 3);
  Thomas.addItem("sword");
  Thomas.addItem("Beretta");
  Thomas.addItem("Semtex");
  Thomas.addItem("Tank");
  Thomas.addItem("Tank");
  // Thomas.displayStatus();

  Team beautiful("Beatiful");
  beautiful.addWarrior(Ridge);
  beautiful.addWarrior(Erik);
  beautiful.addWarrior(Thomas);

  Warrior Goku = Warrior("Goku", 100, 500, 100, 50, 3);
  Goku.addItem("sword");
  Goku.addItem("arc");
  Goku.addItem("AK-47");
  Goku.addItem("sword");
  // Goku.displayStatus();

  Warrior Gohan = Warrior("Gohan", 100, 150, 440, 27, 2);
  Gohan.addItem("ENMA");
  Gohan.addItem("Beretta");
  Gohan.addItem("Bazooka");
  Gohan.addItem("Helicopter");
  // Gohan.displayStatus();

  Team DragonBall = Team("DragonBall");
  DragonBall.addWarrior(Goku);
  DragonBall.addWarrior(Gohan);

  std::cout << std::endl;

  // Display initial status of both teams
  std::cout << "Team " << DragonBall.getTeamName() << ":\n";
  DragonBall.displayTeamStatus();

  std::cout << "Team " << beautiful.getTeamName() << ":\n";
  beautiful.displayTeamStatus();

  std::cout << "\nStarting the fight...\n";
  Simulation simulation;
  simulation.simulateFight(DragonBall, beautiful);

  return 0;
}
