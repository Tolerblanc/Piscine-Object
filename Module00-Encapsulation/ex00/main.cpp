#include "Account.hpp"
#include "Bank.hpp"

int main()
{
    try {
        Bank b1(1000);
        std::cout << "Bank created\n" << b1 << std::endl;
        int id = b1.addAccount(1000);
        std::cout << "Account added with ID: " << id << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1[id] << std::endl;
        std::cout << "=================================" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bank b1(1000);
        std::cout << "Bank created\n" << b1 << std::endl;
        int id = b1.addAccount(1000);
        std::cout << "Account added with ID: " << id << std::endl;
        std::cout << "Bank status\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.deposit(id, 1000);
        std::cout << "Deposit of 1000 to account " << id << std::endl;
        std::cout << "Bank status\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 500);
        std::cout << "Withdrawal of 500 from account " << id << std::endl;
        std::cout << "Bank status\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 1000);
        std::cout << "Withdrawal of 1000 from account " << id << std::endl;
        std::cout << "Bank status\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 1000);
        std::cout << "Withdrawal of 1000 from account " << id << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}