#include "fight_simulation.h"

void swapTeams(Team &team1, Team &team2)
{
  Team &temp = team1;
  team1 = team2;
  team2 = temp;
}

void Simulation::simulateFight(Team &teamA, Team &teamB) const
{
  std::cout << "The fight begins between team " << teamA.getTeamName() << " and team " << teamB.getTeamName() << "!\n";

  // Seed random number generator (every time program is executed the random numbers differ from each other)
  std::srand(std::time(nullptr));

  while (!teamA.isTeamEmpty() && !teamB.isTeamEmpty())
  {
    for (int team = 1; team <= 2; team++)
    {
      // Team A attacks Team B
      teamAttack(teamA, teamB);

      // fight end for Team B
      if (teamB.isTeamEmpty())
      {
        std::cout << "No more warriors left in Team " << teamB.getTeamName() << "\n";
        displayFinalFightResult(teamB, teamA);
        break;
      }

      if (team == 1)
        swapTeams(teamA, teamB); // team attacker, defender roles inverted!
    }
  }
}

void Simulation::displayFinalFightResult(const Team &team, const Team &anotherTeam) const
{
  std::cout << "Team " << team.getTeamName() << " lost the fight, Team " << anotherTeam.getTeamName() << " won! Fight ended\n\n";
  std::cout << "________Survivals of team " << anotherTeam.getTeamName() << "_______" << std::endl;
  anotherTeam.displayTeamStatus();
}

void Simulation::teamAttack(const Team &teamStricker, Team &teamDefender)
{
  // Team 1 =  {Goku, Gohan, Lilly} attacks Team 2 = {Brooke, Ridge, Thomas, Erik}
  // Team 1 attacks Team 2: indexes must be between 0 and teamX.size() otherwise it is not able to access the element if index = teamXsize() (vectors!!!)
  int strickerIndexT = std::rand() % teamStricker.getSize();              // Random damage between 0 and team1.size - 1
  const Warrior &stricker_team = teamStricker.getWarrior(strickerIndexT); // pick 1 random warrior in the T1

  // bool strickerT1WillingnessToFight_multipleEnemiesT2 = std::rand() % 2; // to generate true or false

  // creating the subteam of T2 that warT1 can handle
  // attacking until there are warriors even if I can handle more warriors
  for (int nWarrior = 1; nWarrior <= stricker_team.getAbility() && !teamDefender.isTeamEmpty(); nWarrior++)
  {
    int defenderIndexT = std::rand() % teamDefender.getSize(); // Random damage between 0 and teamDefender.size - 1
    Warrior &defender_team = teamDefender.getWarrior(defenderIndexT);

    // calculate damage
    const int damage_warTStr_ON_warTDef = stricker_team.calculateDamageOnEnemy(); // Random damage between baseDamage and totalDamage
    defender_team.updateCharHealth(-damage_warTStr_ON_warTDef);

    // prints who attacks who and the health score of the defender
    stricker_team.warriorAttackStatus(defender_team, teamStricker.getTeamName(), teamDefender.getTeamName(), damage_warTStr_ON_warTDef);

    // remove defeated character if any
    if (defender_team.getCharHealth() <= 0)
    {
      std::cout << "Team " << teamDefender.getTeamName() << "'s Warrior " << defender_team.getCharName() << " has been defeated!\n\n";
      teamDefender.eraseWarrior(defenderIndexT);
    }
  }
}