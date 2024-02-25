#include <iostream>
#include <vector>
#include <map>
#include "Account.hpp"

class Account;

class Bank
{
private:
	int liquidity;
    float interestRate;
    std::map<int, Account> clientAccounts;

    Bank(const Bank& p_bank);
    Bank& operator=(const Bank& p_bank);

public:
	Bank();
    Bank(int liquidity);
    ~Bank();

	friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank)
	{
		p_os << "Bank informations : " << std::endl;
		p_os << "Liquidity : " << p_bank.liquidity << std::endl;
		for (auto &clientAccount : p_bank.clientAccounts)
        p_os << *clientAccount << std::endl;
		return (p_os);
	}
};