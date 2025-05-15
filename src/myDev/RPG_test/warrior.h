#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include "equipment.h"

class Warrior : public Character // Warrior is a character
{
public:
  Warrior(const std::string &name, int health,
          unsigned int attack, unsigned int defense,
          unsigned int strength, unsigned int ability = 1);
  // getters
  const unsigned int getAttack() const { return attack; }
  const unsigned int getDefense() const { return defense; }
  const unsigned int getStrength() const { return strength; }
  const unsigned int getAbility() const { return ability; }

  void displayStatus() const // overriding the display status of character
  {
    Character::displayStatus();
    std::cout << "Attack: " << attack << "\nDefense: " << defense << "\nStrength: " << strength
              << "\nTotal Damage: " << BASE_DAMAGE + strength << std::endl;
    equipment.displayInventory();
  };

  void warriorAttack(const Warrior &defender, const std::string &teamNameStricker, const std::string &teamNameDefender, int damageStr_ON_Def) const;
  // setter
  void addItem(const std::string &item)
  {
    equipment.addItem(item);
  }

  // TO DO: set attack, defense based on the equipment

private:
  unsigned int attack, defense, strength, ability; // ability to attack more warriors at the same time
  Equipment equipment;                             // composition (Warrior has equipment features)
};

#endif