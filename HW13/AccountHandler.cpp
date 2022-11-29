#include "AccountHandler.h"


AccountHandler::AccountHandler()
	: m_accNum(0)
{
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < m_accNum; i++)
		delete m_accArr[i];
}

int AccountHandler::GetAccIdx(int id) const
{
	for (int i = 0; i < m_accNum; i++)
	{
		if (m_accArr[i]->GetAccID() == id)
			return i;
	}
	return -1;
}

void AccountHandler::ShowMenu(void) const
{
	cout << "-----Menu-----" << endl;
	cout << "1. Open an account" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdraw" << endl;
	cout << "4. Show all account info" << endl;
	cout << "5. Exit" << endl;
}

void AccountHandler::MakeAccount()
{
	int choice;
	cout << "[Select Account Type]" << endl;
	cout << "1. Saving Account" << endl;
	cout << "2. High Credit Account" << endl;
	cout << "Select: ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		MakeSavingAccount();			// if 1 chosen call MakeSavingAccount
		break;
	case 2:
		MakeHighCreditAccount();		//if 2 chosen call MakeHighCreditAccount
		break;
	default:
		cout << "Invalid selection" << endl;	// otherwise error message
		break;
	}
}

void AccountHandler::DepositMoney()
{
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Amount: ";
	cin >> money;

	int idx = GetAccIdx(id);
	if (idx == -1)
	{
		cout << "Invalid ID" << endl;
		return;
	}

	m_accArr[idx]->Deposit(money);
	cout << "Deposit complete" << endl;
}

void AccountHandler::WithdrawMoney()
{
	int money;
	int id;
	cout << "[Withdraw]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Amount: ";
	cin >> money;

	int idx = GetAccIdx(id);
	if (idx == -1)
	{
		cout << "Invalid ID" << endl;
		return;
	}

	if (m_accArr[idx]->Withdraw(money) == -1)
	{
		cout << "Insufficient balance" << endl;
		return;
	}

	cout << "Withdraw: " << m_accArr[idx]->Withdraw(money) << endl;
}

void AccountHandler::ShowAllAccInfo() const
{
	for (int i = 0; i < m_accNum; i++)
	{
		m_accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

void AccountHandler::MakeSavingAccount()
{
	int id;
	char name[MAX_NAME_LEN];
	int amount;
	int interest;

	cout << "[Make Saving Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit amount: ";
	cin >> amount;
	cout << "Interest rate: ";
	cin >> interest;
	cout << endl;

	m_accArr[m_accNum++] = new SavingAccount(id, amount, name, interest);
}

void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[MAX_NAME_LEN];
	int amount;
	int interest;
	int credit;
	char rate;

	cout << "[Make high credit account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Customer Name: ";
	cin >> name;
	cout << "Deposit Amount: ";
	cin >> amount;
	cout << "Interest rate: ";
	cin >> interest;
	cout << "Special rate (A: 7%, B: 4%, C: 2%): ";
	cin >> rate;

	rate = toupper(rate);
	
	// Set the special rate depending on the input Character
	switch (rate)
	{
	case 'A':
		credit = 7;
		break;
	case 'B':
		credit = 4;
		break;
	case 'C':
		credit = 2;
		break;
	default:
		cout << "Invalid selection" << endl;
		return;
	}

	m_accArr[m_accNum++] = new HighCreditAccount(id, amount, name, interest, credit);
}