#include "fight_simulation.h"

void Simulation::simulateFight(Team &teamA, Team &teamB) const
{
  std::cout << "The fight begins between team " << teamA.getTeamName() << " and team " << teamB.getTeamName() << "!\n";

  // Seed random number generator (every time program is executed the random numbers differ from each other)
  std::srand(std::time(nullptr));

  while (!teamA.isTeamEmpty() && !teamB.isTeamEmpty())
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

    // Team B attacks Team A
    teamAttack(teamB, teamA);

    // fight end for Team A
    if (teamA.isTeamEmpty())
    {
      std::cout << "No more warriors left in Team " << teamA.getTeamName() << "\n";
      displayFinalFightResult(teamA, teamB);
      break;
    }
  }
}

void Simulation::displayFinalFightResult(const Team &team, const Team &anotherTeam) const
{
  std::cout << "Team " << team.getTeamName() << " lost the fight, Team " << anotherTeam.getTeamName() << " won! Fight ended\n\n";
  std::cout << "________Survivals of team " << anotherTeam.getTeamName() << "_______" << std::endl;
  anotherTeam.displayTeamStatus();
}

void Simulation::teamAttack(const Team &teamStricker, Team &teamDefender) const
{
  // Team Stricker =  {Goku, Gohan, Lilly} attacks Team Defender = {Brooke, Ridge, Thomas, Erik}
  // Team Stricker attacks Team Defender: indexes must be between 0 and teamX.size() otherwise it is not able to access the element if index = teamXsize() (vectors!!!)
  int strickerIndexT = std::rand() % teamStricker.getSize();             // Random damage between 0 and teamStricker.size - 1
  const Warrior &stricker_war = teamStricker.getWarrior(strickerIndexT); // pick 1 random warrior in the Team stricker

  bool strickerWillingnessToFight_multipleDefenders = std::rand() % 2; // to generate true or false

  // creating the subteam of T2 that warT1 can handle
  // attacking until there are warriors even if I can handle more warriors
  if (strickerWillingnessToFight_multipleDefenders) // 1 vs more
  {
    for (int nWarrior = 1; nWarrior <= stricker_war.getAbility() && !teamDefender.isTeamEmpty(); nWarrior++)
      updateHealthEraseWarrior(teamStricker, teamDefender, strickerIndexT);
  }
  else // 1 vs 1
    updateHealthEraseWarrior(teamStricker, teamDefender, strickerIndexT);
}

void Simulation::updateHealthEraseWarrior(const Team &teamStricker, Team &teamDefender, int index) const
{
  int defenderIndexT = std::rand() % teamDefender.getSize(); // Random damage between 0 and teamDefender.size - 1
  Warrior &defender_war = teamDefender.getWarrior(defenderIndexT);
  // calculate stricker damage on defender
  const int damage_warTStr_ON_warTDef = teamStricker.getWarrior(index).calculateDamageOnEnemy(); // Random damage between baseDamage and totalDamage
  // update defender health
  defender_war.updateCharHealth(-damage_warTStr_ON_warTDef);
  // prints who attacks who and the health score of the defender
  teamStricker.getWarrior(index).warriorAttackStatus(defender_war, teamStricker.getTeamName(), teamDefender.getTeamName(), damage_warTStr_ON_warTDef);
  // remove defeated character if any
  if (defender_war.getCharHealth() <= 0)
  {
    std::cout << "Team " << teamDefender.getTeamName() << "'s Warrior " << defender_war.getCharName() << " has been defeated!\n\n";
    teamDefender.eraseWarrior(defenderIndexT);
  }
}