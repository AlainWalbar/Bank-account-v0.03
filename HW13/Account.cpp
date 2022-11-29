#include "Account.h"

//Copy constructor
Account::Account(const Account& ref) 
    : m_accID{ref.m_accID}, m_balance{ref.m_balance} 
{
    m_cusName = new char[strlen(ref.m_cusName) + 1];
    strcpy_s(m_cusName,strlen(ref.m_cusName) + 1, ref.m_cusName);
}

Account::Account(int ID, int balance, char* cName)
	: m_accID{ ID }, m_balance{ balance }
{
	int len = strlen(cName) + 1;
	m_cusName = new char[len];
	strcpy_s(m_cusName, len, cName);
}

//Destructor
Account::~Account()
{
	delete[]m_cusName;
} 

int Account::GetAccID(void) const
{
	return m_accID;
}

void Account::Deposit(int money)
{
	m_balance += money;
}

int Account::Withdraw(int money)
{
	if ((m_balance < 0) || (m_balance < money))	//if balance is less than 0 or less than money, then we can't withdraw
		return -1;
	m_balance -= money;
	return money;
}

void Account::ShowAccInfo(void) const
{
	cout << "Account ID: " << m_accID << endl;
	cout << "Name: " << m_cusName << endl;
	cout << "Balance: " << m_balance << endl;
}