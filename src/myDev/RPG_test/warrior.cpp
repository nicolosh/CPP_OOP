#include "warrior.h"

Warrior::Warrior(const std::string &name, int health,
                 unsigned int attack, unsigned int defense,
                 int strength)
    : Character(name, health)
{
  this->attack = attack;
  this->defense = defense;
  this->strength = strength;
}