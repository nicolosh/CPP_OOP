#include "team.h"

void Team::displayTeamStatus() const
{
  for (const auto &warrior : team)
    warrior.displayStatus();
}

Team::Team(const std::string &name) : name(name) {}

Warrior &Team::getWarrior(int index) { return team[index]; }

void Team::eraseWarrior(int index) { team.erase(team.begin() + index); }

void Team::displayFinalFightResult(Team &anotherTeam) const
{
  std::cout << "\nTeam " << this->getTeamName() << " lost the fight, Team " << anotherTeam.getTeamName() << " won!\n\n";
  std::cout << "________Survivals of team " << anotherTeam.getTeamName() << "_______" << std::endl;
  anotherTeam.displayTeamStatus();
}