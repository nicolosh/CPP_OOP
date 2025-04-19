#include "auditor.h"

bool Auditor::verifyAccount(const bankAccount &account)
{
  bool isValid = true;
  // Verify account number format (must be account.MAX_ID_NUMBER_LENGTH digits)
  unsigned int length = account.IDnumber.length();
  if (length != account.MAX_ID_NUMBER_LENGTH)
  {
    std::cout << "Account number must be " << account.MAX_ID_NUMBER_LENGTH << " digits. Got " << length << " instead." << std::endl;
    isValid = false;
  }
  for (char c : account.IDnumber)
  {
    if (!isdigit(c))
    {
      std::cout << "Invalid account number format: " << account.IDnumber << std::endl;
      isValid = false;
      break;
    }
  }

  // Access account balance and transaction count directly via friend relationship
  // Verify balance is non-negative
  if (account.totalBalance < 0)
  {
    std::cout << "Negative account balance: " << account.totalBalance << std::endl;
    isValid = false;
  }

  std::cout << "Total transactions: " << account.numberTrans << std::endl;
  std::cout << "Current balance: $" << account.totalBalance << std::endl;

  return isValid;
}