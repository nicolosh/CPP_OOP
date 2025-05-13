#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
  // Constructor, destructor
  Character(const std::string &name, int health);
  ~Character();
  // methods
  void displayStatus() const;

  // getters
  std::string getCharName() const { return characterName; }
  int getCharHealth() const { return health; }
  unsigned int getDamage() const { return BASE_DAMAGE; }

  // setters
  void setCharName(const std::string &newName) { characterName = newName; }
  void updateCharHealth(int healthPoints)
  {
    int updateHealth = health + healthPoints;

    if (updateHealth > MAX_HEALTH)
      health = MAX_HEALTH;
    else if (updateHealth < 0)
      health = 0;
    else
      health = updateHealth;
  }

protected:
  static const unsigned int BASE_DAMAGE = 10; // fixed and constant
  static const unsigned int MAX_HEALTH = 100;
  std::string characterName; // variable
  unsigned int health;       // variable

private:
  void validateEmptyString(const std::string &str, const std::string &fieldName = "") const;
};

#endif