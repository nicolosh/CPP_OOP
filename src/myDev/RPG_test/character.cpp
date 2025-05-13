#include "character.h"

#include <iostream>

Character::Character(const std::string &name, int health, const std::string &action)
    : health(health)
{
  validaEmptyString(name, "name");

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
            << health << "\nAction: "
            << action << std::endl;
}

void Character::validaEmptyString(const std::string &str, const std::string &fieldName) const
{
  if (str.empty())
    throw std::invalid_argument("Character's " + fieldName + " cannot be empty");
}