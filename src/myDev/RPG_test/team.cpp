#include "team.h"

void Team::displayTeamStatus() const
{
  for (const auto &warrior : team)
    warrior.displayStatus();
}

Team::Team(const std::string &name) : name(name) {}

Warrior &Team::getWarrior(int index) { return team[index]; }
const Warrior &Team::getWarrior(int index) const { return team[index]; }

void Team::eraseWarrior(int index) { team.erase(team.begin() + index); }
