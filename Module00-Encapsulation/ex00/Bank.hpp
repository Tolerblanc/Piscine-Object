#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <exception>
#include "Account.hpp"

class Account;

class Bank
{
private:
	int liquidity;
    float interestRate;
    std::map<int, Account> clientAccounts;
    int nextId;
    std::deque<int> availableIds;

    Bank(const Bank& p_bank);
    Bank& operator=(const Bank& p_bank);

public:
	Bank();
    Bank(int liquidity);
    ~Bank();

    const int& getLiquidity() const;

    void setinterestRate(float p_interestRate);
    const float& getinterestRate() const;

    const int& addAccount(int p_balance);
    const int& loan(int p_amount);
    void deposit(int p_id, int p_amount);
    void withdraw(int p_id, int p_amount);
    void deleteAccount(int p_id);

    const Account& getAccount(int p_id) const;
    const Account& operator[](int p_id) const;

    class InvalidAccountIdException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

    class InvalidAmountException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

    class LoanAccountDeletionException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

    class NotEnoughLiquidityException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

    class NotEnoughAccountPoolException : public std::exception
    {
        public:
            const char * what(void) const throw();
    };

	friend std::ostream& operator<< (std::ostream& p_os, const Bank& p_bank);
};