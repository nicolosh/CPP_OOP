#include "warrior.h"
#include <cstdlib> // For random numbers
#include <ctime>   // For seeding random numbers
// using namespace std;

void simulateFight(std::vector<Warrior> &team1, std::vector<Warrior> &team2)
{
  std::cout << "The fight begins between team A and team B!\n";

  // Seed random number generator
  std::srand(std::time(nullptr));

  while (!team1.empty() && !team2.empty())
  {
    // Team 1 attacks Team 2: indexes must be between 0 and teamX.size() otherwise it is not able to access the element if index = teamXsize() (vectors!!!)
    int attackerIndexT1 = std::rand() % team1.size(); // Random damage between 0 and team1.size - 1
    int defenderIndexT2 = std::rand() % team2.size(); // Random damage between 0 and team2.size - 1

    // picks 2 random warriors in the 2 teams
    Warrior &attacker_team1 = team1[attackerIndexT1];
    Warrior &defender_team2 = team2[defenderIndexT2];

    int damage_warT1_ON_warT2 = std::rand() % (attacker_team1.getStrength() + 1) + attacker_team1.getDamage(); // Random damage between baseDamage and totalDamage
    defender_team2.updateCharHealth(-damage_warT1_ON_warT2);

    std::cout << attacker_team1.getCharName() << " from T1 attacks " << defender_team2.getCharName()
              << " from T2 for " << damage_warT1_ON_warT2 << " damage. "
              << defender_team2.getCharName() << "'s health is now " << defender_team2.getCharHealth() + damage_warT1_ON_warT2
              << " - " << damage_warT1_ON_warT2 << " = " << defender_team2.getCharHealth() << ".\n";

    if (defender_team2.getCharHealth() <= 0)
    {
      std::cout << "Team 2's Warrior " << defender_team2.getCharName() << " has been defeated!\n";
      team2.erase(team2.begin() + defenderIndexT2); // Remove defeated character
    }

    if (team2.empty())
      break;

    // Team 2 attacks team 1
    int attackerIndexT2 = std::rand() % team2.size();
    int defenderIndexT1 = std::rand() % team1.size();

    Warrior &attacker_team2 = team2[attackerIndexT2];
    Warrior &defender_team1 = team1[defenderIndexT1];

    int damage_warT2_ON_warT1 = std::rand() % (attacker_team2.getStrength() + 1) + attacker_team2.getDamage();
    defender_team1.updateCharHealth(-damage_warT2_ON_warT1);

    std::cout << attacker_team2.getCharName() << " from T2 attacks " << defender_team1.getCharName()
              << " from T1 for " << damage_warT2_ON_warT1 << " damage. "
              << defender_team1.getCharName() << "'s health is now " << defender_team1.getCharHealth() + damage_warT2_ON_warT1
              << " - " << damage_warT2_ON_warT1 << " = " << defender_team1.getCharHealth() << ".\n";

    if (defender_team1.getCharHealth() <= 0)
    {
      std::cout << "Team 1's Warrior " << defender_team1.getCharName() << " has been defeated!\n";
      team1.erase(team1.begin() + defenderIndexT1);
    }
    if (team1.empty())
      break;
  }

  if (team1.empty())
  {
    std::cout << "Team 1 lost the fight, Team 2 won!\n\n";
    std::cout << "________Survivals of team 2__________ " << std::endl;
    for (const auto &member : team2)
      member.displayStatus();
  }
  else if (team2.empty())
  {
    std::cout << "Team 2 lost the fight, Team 1 won!\n\n";
    std::cout << "__________Survivals of team 1_________: " << std::endl;
    for (const auto &member : team1)
      member.displayStatus();
  }
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

  std::vector<Warrior> teamA = {Ridge, Erik};

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
  std::vector<Warrior> teamB = {Donna, Brooke};

  std::cout << std::endl;

  // Display initial status of both teams
  std::cout << "Team A:\n";
  for (const auto &member : teamA)
    member.displayStatus();

  std::cout << "Team B:\n";
  for (const auto &member : teamB)
    member.displayStatus();

  std::cout << "\nStarting the fight...\n";
  simulateFight(teamA, teamB);
  return 0;
}