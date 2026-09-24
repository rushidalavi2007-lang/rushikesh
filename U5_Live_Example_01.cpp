#include <iostream>
#include <exception>
#include <string>
using namespace std;

class InsufficientFundsException : public exception {
public:
    const char* what() const noexcept override {
        return "Transaction Failed: Insufficient Balance!";
    }
};

class BankAccount {
private:
    double balance;
public:
    BankAccount(double b) : balance(b) {}
    void withdraw(double amt) {
        if (amt > balance) throw InsufficientFundsException();
        balance -= amt;
        cout << "Withdrawal successful. Current Balance: Rs. " << balance << endl;
    }
};

int main() {
    BankAccount acc(5000.0);
    try {
        cout << "Attempting valid withdrawal..." << endl;
        acc.withdraw(1000.0);
        cout << "Attempting invalid withdrawal..." << endl;
        acc.withdraw(7000.0);
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
