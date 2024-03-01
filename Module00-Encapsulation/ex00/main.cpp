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
        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.deposit(id, 1000);
        std::cout << "Deposit of 1000 to account " << id << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 500);
        std::cout << "Withdrawal of 500 from account " << id << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 1000);
        std::cout << "Withdrawal of 1000 from account " << id << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
        b1.withdraw(id, 1000);
        std::cout << "Withdrawal of 1000 from account " << id << std::endl;
        std::cout << "ID " << id << " Account Info: " << b1.getAccount(id) << std::endl;
        std::cout << "=================================" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bank b1(1000);
        std::cout << "Bank created\n" << b1 << std::endl;
        int id1 = b1.addAccount(1000);
        std::cout << "Account added with ID: " << id1 << std::endl;
        std::cout << b1[id1] << std::endl;
        int id2 = b1.addAccount(1000);
        std::cout << "Account added with ID: " << id2 << std::endl;
        std::cout << b1[id2] << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;
        int id3 = b1.addAccount(1000);
        std::cout << "Account added with ID: " << id3 << std::endl;
        std::cout << b1[id3] << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << "=================================" << std::endl;

        b1.deposit(id1, 420);
        std::cout << "Deposit of 420 to account " << id1 << std::endl;
        std::cout << b1[id1] << std::endl;

        b1.deposit(id2, 240);
        std::cout << "Deposit of 240 to account " << id2 << std::endl;
        std::cout << b1[id2] << std::endl;

        b1.deposit(id3, 100);
        std::cout << "Deposit of 100 to account " << id3 << std::endl;
        std::cout << b1[id3] << std::endl;

        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << b1[id1] << std::endl;
        std::cout << b1[id2] << std::endl;
        std::cout << b1[id3] << std::endl;

        std::cout << "=================================" << std::endl;
        b1.withdraw(id1, 100);
        std::cout << "Withdrawal of 100 from account " << id1 << std::endl;
        std::cout << b1[id1] << std::endl;

        b1.withdraw(id2, 100);
        std::cout << "Withdrawal of 100 from account " << id2 << std::endl;
        std::cout << b1[id2] << std::endl;

        b1.withdraw(id3, 4242);
        std::cout << "Withdrawal of 4242 from account " << id3 << std::endl;
        std::cout << b1[id3] << std::endl;

        std::cout << "----Bank status----\n" << b1 << std::endl;
        std::cout << b1[id1] << std::endl;
        std::cout << b1[id2] << std::endl;
        std::cout << b1[id3] << std::endl;

        std::cout << "=================================" << std::endl;
        b1.deleteAccount(id1);
        std::cout << "Account " << id1 << " deleted" << std::endl;
        std::cout << "----Bank status----\n" << b1 << std::endl;

        b1.deleteAccount(42);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bank b1(1000);
        std::cout << "Bank created\n" << b1 << std::endl;

        int id1 = b1.loan(500);
        std::cout << "Loan of 500 requested\n";
        std::cout << "Account added with ID: " << id1 << std::endl;
        std::cout << b1[id1] << std::endl;

        int id2 = b1.loan(1000);
        std::cout << "Account added with ID: " << id2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}