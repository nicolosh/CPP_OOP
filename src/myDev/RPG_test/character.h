#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
public:
  // Constructor, destructor
  Character(const std::string &name, int health, const std::string &action);
  ~Character();
  // methods
  void displayStatus() const;

  // getters
  std::string getCharName() const { return characterName; }
  int getCharHealth() const { return health; }
  std::string getAction() const { return action; }
  // unsigned int getDamage() const { return BASE_DAMAGE; }

  // setters
  void setCharacterName(const std::string &newName) { characterName = newName; }
  void setHealth(int healthPoints) { health += healthPoints; }
  void setAction(const std::string &action) { this->action = action; }

protected:
  // static const unsigned int BASE_DAMAGE = 10; // fixed and constant
  std::string characterName; // variable
  unsigned int health;       // variable
  std::string action;        // variable

private:
  void validateEmptyString(const std::string &str, const std::string &fieldName = "") const;
};

#endif