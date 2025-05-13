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
  // unsigned int getDamage() const { return BASE_DAMAGE; }
  std::string getAction() const { return action; }

  // setters
  void setCharacterName(const std::string &newName) { characterName = newName; }
  void setHealth(int healthPoints) { health += healthPoints; }
  void setAction(const std::string &action) { this->action = action; }

protected:
  // static const unsigned int BASE_DAMAGE = 10; // fixed and constant
  unsigned int health;       // variable
  std::string characterName; // variable
  std::string action;        // variable

private:
  void validaEmptyString(const std::string &str, const std::string &fieldName = "") const;
};

#endif