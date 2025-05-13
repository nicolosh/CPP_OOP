#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include "equipment.h"

class Warrior : public Character // Warrior is a character
{
public:
  Warrior(const std::string &name, unsigned int health,
          const unsigned int attack, const unsigned int defense,
          const unsigned int strength, const std::string &action);
  // getters
  const unsigned int getAttack() { return attack; }
  const unsigned int getDefense() { return defense; }
  const unsigned int getStrength() { return strength; }

  void displayStatus() const // overriding the display status of character
  {
    Character::displayStatus();
    std::cout << "Attack: " << attack << "\nDefense: " << defense << "\nStrength: " << strength << "\n";
    equipment.displayInventory();
  };

  void addItem(const std::string &item) { equipment.addItem(item); }

private:
  unsigned int attack, defense, strength; // constants
  Equipment equipment;                    // composition (Warrior has equipment features)
};

#endif