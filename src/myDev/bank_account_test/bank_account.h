#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include <iostream>
#include <ctime>

class bankAccount
{
public:
  bankAccount(const std::string &number, float initialBalance, long int accessCode);
  ~bankAccount();
  void deposit(float amount);
  void withdraw(float amount);
  void displayBalance() const; // Should update accessCount

  // getters
  unsigned int getPIN() { return pin; };
  std::string getID() { return IDnumber; };
  float getTotal() { return totalBalance; };
  unsigned int getNumTrans() { return numberTrans; };
  std::time_t getPinFirstTime() { return pinSetFirstTime; };

  // setters
  void setNewPIN(long int accessCode, std::time_t &currentTime);

private:
  friend class Auditor; // can access the private bank_account members
  static const unsigned int MAX_DEPOSIT = 100000;
  static const unsigned int MAX_ID_NUMBER_LENGTH = 10; // indeed it corresponds to the max number of digits the unsigned int type can support
  static const unsigned int MAX_DAYS_RESET_PIN = 1;
  static const unsigned int MAX_CONSECUTIVE_PIN_DIGITS = 3;
  static const unsigned int MAX_SAME_PIN_DIGITS = 4; // every digit must not be repeated for more than MAX_SAME_PIN_DIGITS times
  static const unsigned int MAX_NUMBER_PIN_DIGITS = MAX_ID_NUMBER_LENGTH;
  const float seconds1Day = 86400;

  std::string IDnumber;
  unsigned int pin;
  float totalBalance;
  mutable unsigned int numberTrans = 0;
  std::time_t pinSetFirstTime;

  // New member to track the time when the PIN was last set
  bool resetPIN(std::time_t &currentTime) const;
  int isPinValid(long int pin) const;
  bool pinSameDigits(long int pin) const;
  bool pinConsecDigits(long int pin) const;
  unsigned int numberOfDigits(long int n) const;
};

#endif