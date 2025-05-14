#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"
#include "equipment.h"

class Warrior : public Character // Warrior is a character
{
public:
  Warrior(const std::string &name, int health,
          unsigned int attack, unsigned int defense,
          int strength);
  // getters
  unsigned int getAttack() const { return attack; }
  unsigned int getDefense() const { return defense; }
  int getStrength() const { return strength; }

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
  unsigned int attack, defense; // constant
  int strength;                 // constant
  Equipment equipment;          // composition (Warrior has equipment features)
};

#endif