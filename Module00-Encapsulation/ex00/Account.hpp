#pragma once
#include <iostream>

class Bank;

class Account
{
private:
	double balance;
    int id;
    friend class Bank;

	Account(int id, int balance);

    Account();
    Account(const Account& p_account);
    Account& operator=(const Account& p_account);

public:
    ~Account();
    const int& getId() const;
    const double& getBalance() const;
};

std::ostream& operator<< (std::ostream& p_os, const Account& p_account);
