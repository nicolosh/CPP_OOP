#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

class Equipment
{
public:
  void displayInventory() const;
  std::unordered_map<std::string, int> countDuplicateItems() const;
  // setter
  void addItem(const std::string &item);
  // getter
  std::vector<std::string> getInventoryList() const { return inventoryList; }

protected:
  std::vector<std::string> inventoryList;
};

#endif