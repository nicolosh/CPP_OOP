#include "character.h"
#include <iostream>

Character::Character(const std::string &name, int health)
    : health(health)
{
  validateEmptyString(name, "name");

  characterName = name;
}

Character::~Character()
{
  // characterName[0] = toupper(characterName[0]);
  // std::cout << characterName << " is being deleted! " << std::endl;
}

void Character::displayStatus() const
{
  std::cout << "Character Status: \n"
            << "Name: " << characterName
            << "\nHealth Score: "
            << health << "\nBase Damage: "
            << BASE_DAMAGE << std::endl;
}

void Character::validateEmptyString(const std::string &str, const std::string &fieldName) const
{
  if (str.empty())
    throw std::invalid_argument("Character's " + fieldName + " cannot be empty");
}