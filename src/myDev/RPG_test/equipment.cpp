#include "equipment.h"

void Equipment::addItem(const std::string &item)
{
  if (!item.empty())
    inventoryList.push_back(item);
  else
    throw std::invalid_argument(item + "cannot be empty");
}

void Equipment::displayInventory() const
{
  std::cout << "\nEquipment: " << std::endl;

  std::unordered_map<std::string, int> counts = this->countDuplicateItems();
  for (const auto &pair : counts)
  {
    // counts = {{"knife", 3}, {"sword", 1}}
    std::cout << pair.first << ": " << pair.second << (pair.second > 1 ? " items" : " item") << "\n";
  }
  std::cout << std::endl;
}

std::unordered_map<std::string, int> Equipment::countDuplicateItems() const
{
  // La mappa utilizza le stringhe come chiavi e tiene
  // traccia del numero di occorrenze di ciascuna stringa
  // come valore.
  std::unordered_map<std::string, int> itemCounts;
  for (const auto &item : getInventoryList())
    itemCounts[item]++;

  return itemCounts;
}