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
  std::cout << "Equipment: " << std::endl;
  for (const auto &item : inventoryList)
    std::cout << "- " << "" << item << "\n";
}
