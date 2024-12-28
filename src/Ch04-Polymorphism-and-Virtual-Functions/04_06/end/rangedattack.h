#ifndef RANGED_ATTACK_H
#define RANGED_ATTACK_H

#include "ability.h"

class RangedAttack : public Ability
{
public:
  RangedAttack(const std::string &name, int range);

  // TODO: Override use()
  // TODO: Override describe()

private:
  int rangeValue; // Range in meters
};

#endif