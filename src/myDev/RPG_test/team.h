#ifndef TEAM_H
#define TEAM_H

#include "warrior.h"

class Team
{
public:
  Team(const std::string &name);

  void displayTeamStatus() const;
  void addWarrior(const Warrior &warrior) { team.push_back(warrior); }
  void displayFinalFightResult(const Team &anotherTeam) const;

  const int getSize() const { return team.size(); }
  Warrior &getWarrior(int index);
  const std::string &getTeamName() const { return name; }

  bool isTeamEmpty() const { return team.empty(); }
  void eraseWarrior(int index);

protected:
  std::string name;

private:
  std::vector<Warrior> team;
};

#endif