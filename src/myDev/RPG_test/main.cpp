#include "team.h"
#include <cstdlib> // For random numbers
#include <ctime>   // For seeding random numbers
// using namespace std;

void simulateFight(Team &team1, Team &team2)
{
  std::cout << "The fight begins between team " << team1.getTeamName() << " and team " << team2.getTeamName() << "!\n";

  // Seed random number generator
  std::srand(std::time(nullptr));

  while (!team1.isTeamEmpty() && !team2.isTeamEmpty())
  {
    // Team 1 attacks Team 2: indexes must be between 0 and teamX.size() otherwise it is not able to access the element if index = teamXsize() (vectors!!!)
    int strickerIndexT1 = std::rand() % team1.getSize(); // Random damage between 0 and team1.size - 1
    int defenderIndexT2 = std::rand() % team2.getSize(); // Random damage between 0 and team2.size - 1

    // picks 2 random warriors in the 2 teams
    Warrior &stricker_team1 = team1.getWarrior(strickerIndexT1);
    Warrior &defender_team2 = team2.getWarrior(defenderIndexT2);

    // calculate damage
    int damage_warT1_ON_warT2 = std::rand() % (stricker_team1.getStrength() + 1) + stricker_team1.getDamage(); // Random damage between baseDamage and totalDamage
    defender_team2.updateCharHealth(-damage_warT1_ON_warT2);

    // prints who attacks who and the health score of the defender
    stricker_team1.warriorAttack(defender_team2, team1.getTeamName(), team2.getTeamName(), damage_warT1_ON_warT2);

    // remove defeated character if any
    if (defender_team2.getCharHealth() <= 0)
    {
      std::cout << "Team " << team2.getTeamName() << "'s Warrior " << defender_team2.getCharName() << " has been defeated!\n";
      team2.eraseWarrior(defenderIndexT2);
    }

    // fight end for team 2
    if (team2.isTeamEmpty())
      break;

    // Team 2 attacks team 1
    int strickerIndexT2 = std::rand() % team2.getSize();
    int defenderIndexT1 = std::rand() % team1.getSize();

    Warrior &stricker_team2 = team2.getWarrior(strickerIndexT2);
    Warrior &defender_team1 = team1.getWarrior(defenderIndexT1);

    int damage_warT2_ON_warT1 = std::rand() % (stricker_team2.getStrength() + 1) + stricker_team2.getDamage();
    defender_team1.updateCharHealth(-damage_warT2_ON_warT1);

    stricker_team2.warriorAttack(defender_team1, team2.getTeamName(), team1.getTeamName(), damage_warT2_ON_warT1);

    if (defender_team1.getCharHealth() <= 0)
    {
      std::cout << "Team " << team1.getTeamName() << "'s Warrior " << defender_team1.getCharName() << " has been defeated!\n";
      team1.eraseWarrior(defenderIndexT1);
    }
    if (team1.isTeamEmpty())
      break;
  }

  if (team1.isTeamEmpty())
    team1.displayFinalFightResult(team2);
  else if (team2.isTeamEmpty())
    team2.displayFinalFightResult(team1);
}

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
  Warrior Ridge = Warrior("Ridge", 100, 200, 300, 35);
  Ridge.addItem("sword");
  Ridge.addItem("Beretta");
  Ridge.addItem("AK-47");
  Ridge.addItem("AK-47");
  Ridge.addItem("Molotov");
  // Ridge.displayStatus();

  Warrior Erik = Warrior("Erik", 100, 250, 340, 15);
  Erik.addItem("ENMA");
  Erik.addItem("Beretta");
  Erik.addItem("Bazooka");
  Erik.addItem("Helicopter");
  // Erik.displayStatus();

  Warrior Thomas = Warrior("Thomas", 100, 210, 130, 24);
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

  Warrior Donna = Warrior("Donna", 100, 500, 100, 50);
  Donna.addItem("sword");
  Donna.addItem("arc");
  Donna.addItem("AK-47");
  Donna.addItem("sword");
  // Donna.displayStatus();

  Warrior Brooke = Warrior("Brooke", 100, 150, 440, 27);
  Brooke.addItem("ENMA");
  Brooke.addItem("Beretta");
  Brooke.addItem("Bazooka");
  Brooke.addItem("Helicopter");
  // Brooke.displayStatus();

  Team DragonBall = Team("DragonBall");
  DragonBall.addWarrior(Donna);
  DragonBall.addWarrior(Brooke);

  std::cout << std::endl;

  // Display initial status of both teams
  std::cout << "Team " << DragonBall.getTeamName() << ":\n";
  DragonBall.displayTeamStatus();

  std::cout << "Team " << beautiful.getTeamName() << ":\n";
  beautiful.displayTeamStatus();

  std::cout << "\nStarting the fight...\n";
  simulateFight(DragonBall, beautiful);
  return 0;
}