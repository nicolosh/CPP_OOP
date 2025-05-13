#include "warrior.h"

Warrior::Warrior(const std::string &name, unsigned int health,
                 const unsigned int attack, const unsigned int defense,
                 const unsigned int strength, const std::string &action)
    : Character(name, health, action)
{
  this->attack = attack;
  this->defense = defense;
  this->strength = strength;
}