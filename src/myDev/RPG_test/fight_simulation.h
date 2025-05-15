#ifndef FIGHT_SIMULATION_H
#define FIGHT_SIMULATION_H

#include "team.h"
#include <ctime>

class Simulation
{
public:
  void displayFinalFightResult(const Team &team, const Team &anotherTeam) const;
  static void teamAttack(const Team &teamStricker, Team &teamDefender);
  void simulateFight(Team &teamA, Team &teamB) const;
};

void swapTeams(Team &team1, Team &team2);

#endif