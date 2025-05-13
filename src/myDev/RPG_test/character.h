#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "equipment.h"

class Character
{
public:
  // Constructor, destructor
  Character(const std::string &name, int health, const std::string &action);
  ~Character();
  // methods
  void actionIsDoing() const;
  void displayStatus() const;

  // getters
  std::string getCharName() const { return characterName; }
  int getCharHealth() const { return health; }
  std::string getAction() const { return action; }

  // setters
  void setCharacterName(const std::string &newName);
  void setPoints(int points);

protected:
  int health;
  static const unsigned int BASE_DAMAGE = 10;
  std::string characterName;
  std::string action;

private:
  void validateAction(const std::string &action) const;
  void validaEmptyString(const std::string &str, const std::string &fieldName = "") const;
};

#endif