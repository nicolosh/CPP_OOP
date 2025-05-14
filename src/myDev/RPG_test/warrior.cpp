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

void Warrior::warriorAttack(const Warrior &defender, const std::string& teamNameStricker, const std::string &teamNameDefender, int damageStr_ON_Def) const
{
  std::cout << this->getCharName() << " from T" + teamNameStricker + " attacks " << defender.getCharName()
            << " from T" + teamNameDefender + " for " << damageStr_ON_Def << " damage. "
            << defender.getCharName() << "'s health is now " << defender.getCharHealth() + damageStr_ON_Def
            << " - " << damageStr_ON_Def << " = " << defender.getCharHealth() << ".\n";
}