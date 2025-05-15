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
  const unsigned int getAbility() const { return multipleFights; }
  const unsigned int getDamage() const { return BASE_DAMAGE; }

  void displayStatus() const // overriding the display status of character
  {
    Character::displayStatus();
    std::cout << "Attack: " << attack << "\nDefense: " << defense << "\nStrength: " << strength
              << "\nBase Damage: " << BASE_DAMAGE << "\nAbility to attack more enemy warriors simultaneously: "
              << multipleFights << "\nTotal Damage : " << "( " << BASE_DAMAGE << " + "
              << strength << " ) = " << BASE_DAMAGE + strength << std::endl;
    equipment.displayInventory();
  };

  void warriorAttackStatus(const Warrior &defender, const std::string &teamNameStricker, const std::string &teamNameDefender, int damageStr_ON_Def) const;
  // setter
  void addItem(const std::string &item) { equipment.addItem(item); }

  // Random damage between baseDamage and totalDamage = baseDamage + strength
  const int calculateDamageOnEnemy() const { return std::rand() % (strength + 1) + BASE_DAMAGE; }

private:
  unsigned int attack, defense, strength, multipleFights; // ability to attack more warriors at the same time
  Equipment equipment;                                    // composition (Warrior has equipment features)
  static const unsigned int BASE_DAMAGE = 10;             // fixed and constant
};

#endif