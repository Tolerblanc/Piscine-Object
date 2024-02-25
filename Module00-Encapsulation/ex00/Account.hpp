#include "Bank.hpp"

class Account
{
private:
    int id;
	double balance;
    friend class Bank;

	Account(int id, int balance);

    Account();
    ~Account();
    Account(const Account& p_account);
    Account& operator=(const Account& p_account);

public:
    const int& getId() const;
    const double& getBalance() const;
};

std::ostream& operator<< (std::ostream& p_os, const Account& p_account);
