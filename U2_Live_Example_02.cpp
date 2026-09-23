#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PaymentMethod {
protected:
    string transactionId;
    double amount;
public:
    PaymentMethod(string tid, double amt) : transactionId(tid), amount(amt) {}
    virtual bool processPayment() const = 0;
    virtual ~PaymentMethod() {}
};

class CreditCardPayment : public PaymentMethod {
private:
    string cardNumber;
public:
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), cardNumber(card) {}

    bool processPayment() const override {
        cout << "Credit Card TXN: " << transactionId 
             << " | Amount: Rs. " << amount << " using " << cardNumber << " completed." << endl;
        return true;
    }
};

class UPIPayment : public PaymentMethod {
private:
    string upiId;
public:
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    bool processPayment() const override {
        cout << "UPI TXN: " << transactionId 
             << " | Amount: Rs. " << amount << " via " << upiId << " completed." << endl;
        return true;
    }
};

int main() {
    vector<PaymentMethod*> payments;
    payments.push_back(new CreditCardPayment("TXN001", 2500.0, "XXXX-1234"));
    payments.push_back(new UPIPayment("TXN002", 1200.0, "student@upi"));

    cout << "== Payment Gateway ==" << endl;
    for (int i = 0; i < payments.size(); i++) {
        payments[i]->processPayment();
        delete payments[i];
    }
    return 0;
}
