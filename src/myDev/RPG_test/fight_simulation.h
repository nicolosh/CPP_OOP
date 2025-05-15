#ifndef FIGHT_SIMULATION_H
#define FIGHT_SIMULATION_H

#include "team.h"
#include <ctime>

class Simulation
{
public:
  void displayFinalFightResult(const Team &team, const Team &anotherTeam) const;
  void teamAttack(const Team &teamStricker, Team &teamDefender) const;
  void simulateFight(Team &teamA, Team &teamB) const;
  void updateHealthEraseWarrior(const Team &teamStricker, Team &teamDefender, int index) const;
};


#endif