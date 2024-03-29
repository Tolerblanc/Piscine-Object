#include "Bank.hpp"

Bank::Bank() : liquidity(0), interestRate(0.05), nextId(0)
{
}

Bank::Bank(int p_liquidity) : liquidity(p_liquidity), interestRate(0.05), nextId(0)
{
}

Bank::~Bank()
{
}

int Bank::getPoolSize() const
{
    return (clientAccounts.size());
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

    Account *newAccount = new Account(id, p_balance);
    this->clientAccounts[id] = newAccount;
    return (this->clientAccounts.at(id)->getId());
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
    
    double prevBalance = clientAccounts.at(p_id)->getBalance();
    this->clientAccounts.erase(p_id);

    this->liquidity += p_amount * interestRate;
    p_amount -= p_amount * interestRate;

    Account *newAccount = new Account(p_id, prevBalance + p_amount);
    this->clientAccounts[p_id] = newAccount;
}

void Bank::withdraw(int p_id, int p_amount)
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    if (p_amount <= 0 || p_amount > clientAccounts.at(p_id)->getBalance())
        throw InvalidAmountException();

    double prevBalance = clientAccounts.at(p_id)->getBalance();
    this->clientAccounts.erase(p_id);

    Account *newAccount = new Account(p_id, prevBalance - p_amount);
    this->clientAccounts[p_id] = newAccount;
}

void Bank::deleteAccount(int p_id)
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    if (clientAccounts.at(p_id)->getBalance() < 0)
        throw LoanAccountDeletionException();
    this->availableIds.push_back(p_id);
    this->clientAccounts.erase(p_id);
}

const Account& Bank::getAccount(int p_id) const
{
    if (clientAccounts.find(p_id) == clientAccounts.end())
        throw InvalidAccountIdException();
    return (*clientAccounts.at(p_id));
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

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank liquidity: " << p_bank.getLiquidity() << std::endl;
    p_os << "Bank interest rate: " << p_bank.getinterestRate() << std::endl;
    p_os << "Bank accounts: " << p_bank.getPoolSize() << std::endl;
    return (p_os);
}