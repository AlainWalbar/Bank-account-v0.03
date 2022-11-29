using namespace std;

class Account {
private:
	int m_accID;
	int m_balance;
	char* m_cusName;
public:
	Account(int ID, int balance, char* cname)
		: m_accID{ ID }, m_balance{ balance }
	{
		int len = strlen(cname) + 1;
		m_cusName = new char[len];
		strcpy_s(m_cusName, len, cname);
	}
	~Account() {
		delete[]m_cusName;
	}
	int GetAccID(void) {
		return m_accID;
	}
	void Deposit(int money) {
		if (money > 0)
			m_balance += money;
	}
	int Withdraw(int money) {
		if ((money < 0) || (money > m_balance))
			return -1;
		m_balance -= money;
		return money;
	}
	void ShowAccInfo(void) {
		cout << "Account ID: " << m_accID
			<< endl;
		cout << "Name: " << m_cusName << endl;
		cout << "Balance: " << m_balance
			<< endl << endl;
	}
};