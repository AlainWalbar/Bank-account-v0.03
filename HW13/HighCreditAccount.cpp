#include "HighCreditAccount.h"

HighCreditAccount::HighCreditAccount(int ID, int balance, char* cName, int rate, int credit)
    : SavingAccount(ID, balance, cName, rate), m_SpecialRate{ credit }
{
}

void HighCreditAccount::Deposit(int money)
{
    SavingAccount::Deposit(money);
    Account::Deposit(money * (m_SpecialRate / 100.0));
}
