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
    int attackerIndex1 = std::rand() % team1.size(); // Random damage between 0 and team1.size - 1
    int defenderIndex2 = std::rand() % team2.size(); // Random damage between 0 and team2.size - 1

    // picks 2 random warriors in the 2 teams
    Warrior &attacker_team1 = team1[attackerIndex1];
    Warrior &defender_team2 = team2[defenderIndex2];

    int damage_warT1_ON_warT2 = std::rand() % 21 + 10; // Random damage between 10 and 30
    defender_team2.updateCharHealth(-damage_warT1_ON_warT2);
    std::cout << attacker_team1.getCharName() << " from Team 1 attacks " << defender_team2.getCharName()
              << " from Team 2 for " << damage_warT1_ON_warT2 << " damage. "
              << defender_team2.getCharName() << "'s health is now " << defender_team2.getCharHealth() << ".\n";

    if (defender_team2.getCharHealth() <= 0)
    {
      std::cout << "Team 2's Warrior " << defender_team2.getCharName() << " has been defeated!\n";
      team2.erase(team2.begin() + defenderIndex2); // Remove defeated character
    }

    if (team2.empty())
      break;

    // Team 2 attacks team 1
    int attackerIndex2 = std::rand() % team2.size();
    int defenderIndex1 = std::rand() % team1.size();

    Warrior &attacker_team2 = team2[attackerIndex2];
    Warrior &defender_team1 = team1[attackerIndex1];

    int damage_warT2_ON_warT1 = std::rand() % 21 + 10;
    defender_team1.updateCharHealth(-damage_warT2_ON_warT1);
    std::cout << attacker_team2.getCharName() << " from Team 2 attacks " << defender_team1.getCharName()
              << " from Team 1 for " << damage_warT2_ON_warT1 << " damage. "
              << defender_team1.getCharName() << "'s health is now " << defender_team1.getCharHealth() << ".\n";

    if (defender_team1.getCharHealth() <= 0)
    {
      std::cout << "Team 1's Warrior " << defender_team1.getCharName() << " has been defeated.\n";
      team1.erase(team1.begin() + defenderIndex1);
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
  Character paperino("paperino", 110);
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

  std::cout << std::endl;
  std::cout << "Creating the warriors for 2 teams\n";
  Warrior Ridge = Warrior("Ridge", 100, 2000, 3000, 350);
  Ridge.addItem("sword");
  Ridge.addItem("Beretta");
  Ridge.addItem("AK-47");
  Ridge.addItem("AK-47");
  // Ridge.displayStatus();

  Warrior Erik = Warrior("Erik", 100, 2500, 3400, 150);
  Erik.addItem("ENMA");
  Erik.addItem("Beretta");
  Erik.addItem("Bazooka");
  Erik.addItem("Helicopter");
  // Erik.displayStatus();

  std::vector<Warrior> teamA = {Ridge, Erik};

  Warrior Donna = Warrior("Donna", 100, 5000, 1000, 50);
  Donna.addItem("sword");
  Donna.addItem("arc");
  Donna.addItem("AK-47");
  Donna.addItem("sword");
  // Donna.displayStatus();

  Warrior Brooke = Warrior("Brooke", 100, 1500, 4400, 250);
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

  std::cout << "\nTeam B:\n";
  for (const auto &member : teamB)
    member.displayStatus();

  std::cout << std::endl;

  std::cout << "\nStarting the fight...\n";
  simulateFight(teamA, teamB);
  return 0;
}