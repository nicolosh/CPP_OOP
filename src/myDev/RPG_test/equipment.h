#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <iostream>

class Equipment
{
public:
  void displayInventory();
  // setter
  void addItem(const std::string &item);
  // getter
  std::vector<std::string> getInventoryList() { return inventoryList; }

private:
  std::vector<std::string> inventoryList;
};

#endif