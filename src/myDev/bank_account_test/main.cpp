#include "auditor.h" // include già "bank_account.h"

int main()
{
  bankAccount nickAccount("nick97", 1000, 1225432232);
  nickAccount.deposit(10020);
  nickAccount.withdraw(9000);
  nickAccount.displayBalance();

  std::time_t currentTime = nickAccount.getPinFirstTime() + 86401; // seconds

  nickAccount.setNewPIN(18274, currentTime);
  nickAccount.displayBalance();

  Auditor auditor;
  std::cout << "The nickAccount is " << (auditor.verifyAccount(nickAccount) ? "set correclty" : "set wrongly") << std::endl;

  return 0;
}