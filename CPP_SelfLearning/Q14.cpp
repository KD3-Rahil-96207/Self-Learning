#include <iostream>
using namespace std;

class BankAccount {
    double balance;

public:
    BankAccount(double b = 0) {
        balance = b;
    }

    void deposit(double amount) {
        if (amount < 0)
            throw amount;
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0)
            throw amount;
        if (amount > balance)
            throw "Insufficient balance";
        balance -= amount;
    }

    void display() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(1000);

    try {
        acc.deposit(500);
        acc.withdraw(2000);
        acc.display();
    }
    catch (double amt) {
        cout << "Invalid amount: " << amt << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}