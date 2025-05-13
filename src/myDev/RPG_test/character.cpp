#include "character.h"

#include <iostream>

Character::Character(const std::string &name, int health, const std::string &action)
{
  if (health < 0)
    throw std::invalid_argument("Health must be positive");
  validaEmptyString(name, "name");
  validateAction(action);

  this->health = health;
  characterName = name;
  this->action = action;
}

Character::~Character()
{
  characterName[0] = toupper(characterName[0]);
  std::cout << characterName << " is being deleted! " << std::endl;
}

void Character::displayStatus() const
{
  std::cout << "Character Status: \n"
            << "Name: " << characterName
            << "\nHealth Score: "
            << health << "\nBasic Damage: "
            << BASE_DAMAGE << "\nAction: "
            << action << std::endl;
}

void Character::actionIsDoing() const
{
  if (action == "attacking")
    std::cout << "The character " << characterName << " is " << action << " for a " << BASE_DAMAGE << " damage points!" << std::endl;
  else if (action == "defending")
    std::cout << "The character " << characterName << " is " << action << " from another character!" << std::endl;
}

// setters
void Character::setCharacterName(const std::string &newName)
{
  characterName = newName;
}

void Character::setPoints(int points)
{
  if (action == "attacking")
    health += points;
  else if (action == "defending")
    health -= points;
}

// validation
void Character::validateAction(const std::string &action) const
{
  validaEmptyString(action, "action");
  if (action != "attacking" && action != "defending")
    throw std::invalid_argument("Character's action is not valid: must be either attacking or defending");
}

void Character::validaEmptyString(const std::string &str, const std::string &fieldName) const
{
  if (str.empty())
    throw std::invalid_argument("Character's " + fieldName + " cannot be empty");
}