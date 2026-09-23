#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accNumber;
    string name;
    double balance;
public:
    Account(int no, string n, double b) : accNumber(no), name(n), balance(b) {}
    void deposit(double amt) { balance += amt; }
    virtual void withdraw(double amt) {
        if (balance >= amt) balance -= amt;
        else cout << "Insufficient funds!" << endl;
    }
    virtual void display() const {
        cout << "Acc: " << accNumber << " | Name: " << name << " | Balance: Rs. " << balance << endl;
    }
    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(int no, string n, double b, double r) : Account(no, n, b), interestRate(r) {}
    void addInterest() { balance += (balance * interestRate / 100.0); }
};

int main() {
    SavingsAccount acc(101, "Siddhant", 5000.0, 4.0);
    acc.deposit(1500.0);
    acc.addInterest();
    cout << "== Bank Account System ==" << endl;
    acc.display();
    return 0;
}
