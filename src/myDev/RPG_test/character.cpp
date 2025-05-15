#include "character.h"

Character::Character(const std::string &name, int health)
    : health(health)
{
  validateEmptyString(name, "name");

  characterName = name;
}

Character::~Character() {}

void Character::displayStatus() const
{
  std::cout << "Character Status: \n"
            << "Name: " << characterName
            << "\nHealth Score: "
            << health << std::endl;
}

void Character::validateEmptyString(const std::string &str, const std::string &fieldName) const
{
  if (str.empty())
    throw std::invalid_argument("Character's " + fieldName + " cannot be empty");
}