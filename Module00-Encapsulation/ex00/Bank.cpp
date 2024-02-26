#include "Bank.hpp"

Bank::Bank() : liquidity(0), interestRate(0.5), nextId(0)
{
}

Bank::Bank(int p_liquidity) : liquidity(p_liquidity), interestRate(0.5), nextId(0)
{
}

Bank::~Bank()
{
}

const int& Bank::getLiquidity() const
{
    return (liquidity);
}

void Bank::setinterestRate(float p_interestRate)
{
    interestRate = p_interestRate;
}

const float& Bank::getinterestRate() const
{
    return (interestRate);
}

const int& Bank::addAccount(int p_balance)
{
    int id;
    if (availableIds.empty() && nextId < 0)
        throw NotEnoughAccountPoolException();
    if (availableIds.empty())
        id = nextId++;
    else
    {
        id = availableIds.front();
        availableIds.pop_front();
    }
    if (p_balance > 0) 
    {
        this->liquidity += p_balance * interestRate;
        p_balance -= p_balance * interestRate;
    }
    this->clientAccounts[id] = Account(id, p_balance);
    return (id);
}

const int& Bank::loan(int p_amount)
{
    if (p_amount > liquidity)
        throw NotEnoughLiquidityException();
    
    this->liquidity -= p_amount;
    return this->addAccount(-p_amount * (1 + interestRate));
}

void Bank::deposit(int p_id, int p_amount)
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    if (p_amount <= 0)
        throw InvalidAmountException();
    
    double prevBalance = clientAccounts[p_id].getBalance();
    this->clientAccounts.erase(p_id);

    this->liquidity += p_amount * interestRate;
    p_amount -= p_amount * interestRate;
    this->clientAccounts[p_id] = Account(p_id, p_amount + prevBalance);
}

void Bank::withdraw(int p_id, int p_amount)
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    if (p_amount <= 0 || p_amount > clientAccounts[p_id].getBalance())
        throw InvalidAmountException();

    double prevBalance = clientAccounts[p_id].getBalance();
    this->clientAccounts.erase(p_id);
    this->clientAccounts[p_id] = Account(p_id, prevBalance - p_amount);
}

void Bank::deleteAccount(int p_id)
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    if (clientAccounts[p_id].getBalance() < 0)
        throw LoanAccountDeletionException();
    this->availableIds.push_back(p_id);
    this->clientAccounts.erase(p_id);
}

const Account& Bank::getAccount(int p_id) const
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    return (clientAccounts.at(p_id));
}

const Account& Bank::operator[](int p_id) const
{
    return (this->getAccount(p_id));
}

const char * Bank::InvalidAccountIdException::what(void) const throw()
{
    return ("Invalid account id");
}

const char * Bank::InvalidAmountException::what(void) const throw()
{
    return ("Invalid amount");
}

const char * Bank::LoanAccountDeletionException::what(void) const throw()
{
    return ("Cannot delete account with a negative balance");
}

const char * Bank::NotEnoughLiquidityException::what(void) const throw()
{
    return ("Not enough liquidity");
}

const char * Bank::NotEnoughAccountPoolException::what(void) const throw()
{
    return ("Not enough account pool");
}

friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank informations : " << std::endl;
    p_os << "Liquidity : " << p_bank.liquidity << std::endl;
    for (auto &clientAccount : p_bank.clientAccounts)
    p_os << *clientAccount << std::endl;
    return (p_os);
}