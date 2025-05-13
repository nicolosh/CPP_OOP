#include "equipment.h"

void Equipment::addItem(const std::string &item)
{
  if (!item.empty())
    inventoryList.push_back(item);
  else
    throw std::invalid_argument(item + "cannot be empty");
}

void Equipment::displayInventory()
{
  std::cout << "____Inventory items____ \n";
  for (auto &item : inventoryList)
  {
    item[0] = toupper(item[0]);
    std::cout << "- " << "" << item << "\n";
  }
}
