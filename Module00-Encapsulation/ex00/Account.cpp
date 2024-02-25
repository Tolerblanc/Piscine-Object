#include "Account.hpp"

Account::Account(int id, int balance) : id(id), balance(balance)
{
}

const int& Account::getId() const
{
    return (this->id);
}

const double& Account::getBalance() const
{
    return (this->balance);
}

std::ostream& operator<< (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.getId() << "] - [" << p_account.getBalance() << "]";
    return (p_os);
}