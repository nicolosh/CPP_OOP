#include "bank_account.h"

bankAccount::bankAccount(const std::string &number, float initialBalance, long int accessCode)
{
  if (numberOfDigits(accessCode) > MAX_NUMBER_PIN_DIGITS)
    throw std::invalid_argument("Too many digits inserted. Only " + std::to_string(MAX_NUMBER_PIN_DIGITS) + " allowed.");
  if (accessCode < 0)
    throw std::invalid_argument("Access code cannot be negative.");

  // ____ PIN VALIDITY ____________
  if (isPinValid(accessCode) == 1) // NO
    throw std::invalid_argument("Access code ( " + std::to_string(accessCode) + " ) is INVALID: there are both at least one monotonic (increasing/decreasing) sequence of digits whose length is longer than the maximum allowed threshold ( " + std::to_string(MAX_CONSECUTIVE_PIN_DIGITS) + " ) and at least one digit which is repeated more than the maximum allowed threshold ( " + std::to_string(MAX_SAME_PIN_DIGITS) + " )");
  else if (isPinValid(accessCode) == 2) // NO
    throw std::invalid_argument("Access code ( " + std::to_string(accessCode) + " ) is INVALID: at least one digit which is repeated more than the maximum allowed threshold ( " + std::to_string(MAX_SAME_PIN_DIGITS) + " )");
  else if (isPinValid(accessCode) == 3) // NO
    throw std::invalid_argument("Access code ( " + std::to_string(accessCode) + " ) is INVALID: at least one monotonic (increasing/decreasing) sequence of digits whose length is longer than the maximum allowed threshold ( " + std::to_string(MAX_CONSECUTIVE_PIN_DIGITS) + " )");
  else if (isPinValid(accessCode) == 4) // YES
    pin = accessCode;

  if (number == "")
    throw std::invalid_argument("The initial balance cannot be less than 0");
  if (number.length() > MAX_ID_NUMBER_LENGTH)
    throw std::invalid_argument("The length of the ID number inserted exceeded the maximum allowed length ( " + std::to_string(MAX_ID_NUMBER_LENGTH) + " )");

  IDnumber = number;

  if (initialBalance < 0)
    throw std::invalid_argument("The initial balance cannot be less than 0");
  totalBalance = initialBalance;

  pinSetFirstTime = std::time(nullptr); // in seconds
  // std::cout << std::asctime(std::localtime(&pinSetFirstTime)); // stampa la data del tempo corrente
}

bankAccount::~bankAccount()
{
  std::cout << "The bank account object is being deleted" << std::endl;
}

void bankAccount::deposit(float amount)
{
  if (amount <= 0)
    throw std::invalid_argument("The amount inserted ( " + std::to_string(amount) + " ) must be greater than 0");
  if (totalBalance + amount > MAX_DEPOSIT)
    throw std::invalid_argument("Maximum deposit value ( " + std::to_string(MAX_DEPOSIT) + " €) reached");
  totalBalance += amount;
  numberTrans++;
}

void bankAccount::withdraw(float amount)
{
  if (amount <= 0)
    throw std::invalid_argument("The amount inserted ( " + std::to_string(amount) + " €) must be greater than 0");
  if (totalBalance < amount)
    throw std::invalid_argument("Not enough money left on your bank account ( " + std::to_string(totalBalance) + " €)");
  totalBalance -= amount;
  numberTrans++;
}

void bankAccount::displayBalance() const
{
  numberTrans++;
  std::cout << "Total balance is: " << totalBalance
            << " €\nAccount number is: " << IDnumber
            << "\nTransactions number is: " << numberTrans
            << "\nPin Number is: " << pin
            << "\nPin set time: " << std::asctime(std::localtime(&pinSetFirstTime))
            << std::endl;

} // Should update accessCount

// check if is the time to reset the PIN
bool bankAccount::resetPIN(std::time_t &currentTime) const
{
  // Calculate the difference in seconds
  double secondsElapsed = std::difftime(currentTime, pinSetFirstTime);

  // Check if the difference in days is greater than or equal to the required threshold
  if (secondsElapsed >= MAX_DAYS_RESET_PIN * seconds1Day)
  {
    std::cout << "Today is "
              << std::asctime(std::localtime(&currentTime))
              << "You need to reset the PIN for security purposes!" << std::endl;
    std::cout << "More than "
              << MAX_DAYS_RESET_PIN
              << " day is passed: exactly "
              << secondsElapsed / seconds1Day
              << " days\n"
              << std::endl;
    return true;
  }
  return false;
}

void bankAccount::setNewPIN(long int accessCode, std::time_t &currentTime)
{
  if (accessCode == pin)
    throw std::invalid_argument("The new pin inserted ( " + std::to_string(accessCode) + ") cannot be equal to the previous one ( " + std::to_string(pin) + ")");

  if (resetPIN(currentTime))
  {
    pin = accessCode;
    pinSetFirstTime = currentTime; // Update the time when the PIN was set
  }
}

// check if each pin digit is repeated more than MAX_SAME_PIN_DIGITS or
// each digit is repeatedly present more than MAX_CONSECUTIVE_PIN_DIGITS times
int bankAccount::isPinValid(long int pin) const
{
  // pin invalid___________
  // sameDigit repeated and consecutive digits = 1
  // sameDigit repeated = 2
  // consecutive Digits = 3
  // ***
  // pin valid = 4
  if (pinConsecDigits(pin) && pinSameDigits(pin))
    return 1;
  else if (pinSameDigits(pin))
    return 2;
  else if (pinConsecDigits(pin))
    return 3;
  // pin valid
  return 4;
}

unsigned int bankAccount::numberOfDigits(long int n) const
{
  unsigned int Ndigits = 0;
  while (n > 0)
  {
    n /= 10;
    Ndigits++;
  }
  return Ndigits;
}

// found if at least one digit is repeated for more than MAX_SAME_PIN_DIGITS
// times in the pin numeric sequence.
bool bankAccount::pinSameDigits(long int pin) const
{
  std::string pinStr = std::to_string(pin);
  bool atLeastOne = false; // PIN VALID
  // 025511535051   0234868188
  for (int i = 0; i < numberOfDigits(pin) - MAX_SAME_PIN_DIGITS && !atLeastOne; i++)
  {
    int sameDigit = 1; // counts how many times each digit is present in the pin numeric sequence
    for (int j = i + 1; j < numberOfDigits(pin); j++)
    {
      if (pinStr[i] == pinStr[j])
        sameDigit++;
    }
    if (sameDigit > MAX_SAME_PIN_DIGITS)
      atLeastOne = true;
  }

  return (atLeastOne ? true : false);
}

// found if there is at least 1 sequence of consecutive digits
// (longer than MAX_CONSECUTIVE_PIN_DIGITS) in increasing or
// decreasing order in pin checking this starting from each digit.

// 1678634 (VALID pin) or 16663210 (INVALID)
// 1123590123 (INVALID)
bool bankAccount::pinConsecDigits(long int pin) const
{
  std::string pinStr = std::to_string(pin);
  bool atLeastOne = false; // PIN VALID

  // Outer loop is repeated the necessary number of times since the window of checking
  // consecutive digits is wide
  for (int i = 0; i < numberOfDigits(pin) - MAX_CONSECUTIVE_PIN_DIGITS && !atLeastOne; i++)
  {
    unsigned int consecIncrDigit = 1;
    unsigned int consecDecrDigit = 1;
    for (int k = 0; k < MAX_CONSECUTIVE_PIN_DIGITS; k++)
    {
      if (pinStr[i] == pinStr[k + i + 1] - (k + 1))
        consecIncrDigit++;
      if (pinStr[i] == pinStr[k + i + 1] + (k + 1))
        consecDecrDigit++;
    }
    if (consecIncrDigit > MAX_CONSECUTIVE_PIN_DIGITS || consecDecrDigit > MAX_CONSECUTIVE_PIN_DIGITS)
      atLeastOne = true; // at least one sequence found ==> invalid PIN
  }

  return (atLeastOne ? true : false);
}