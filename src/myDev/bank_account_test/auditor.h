#ifndef AUDITOR_H
#define AUDITOR_H

#include "bank_account.h"

class Auditor
{
public:
  bool verifyAccount(const bankAccount &account);
};

#endif