#include <iostream>
#include <string>
using namespace std;

class Vehicle {
protected:
    string regNo;
    double ratePerDay;
public:
    Vehicle(string r, double rate) : regNo(r), ratePerDay(rate) {}
    virtual double calculateRent(int days) { return ratePerDay * days; }
    virtual void display() {
        cout << "Registration: " << regNo << endl;
        cout << "Rate per day: " << ratePerDay << endl;
    }
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
    int doors;
public:
    Car(string r, double rate, int d) : Vehicle(r, rate), doors(d) {}
    void display() override {
        Vehicle::display();
        cout << "Doors: " << doors << endl;
    }
};

class Bike : public Vehicle {
    int cc;
public:
    Bike(string r, double rate, int c) : Vehicle(r, rate), cc(c) {}
    double calculateRent(int days) override { return ratePerDay * days * 0.9; }
    void display() override {
        Vehicle::display();
        cout << "Engine Capacity: " << cc << " cc" << endl;
    }
};

int main() {
    Car c("MH12AB1234", 2000.0, 5);
    Bike b("MH12CD5678", 800.0, 150);
    cout << "Car Details" << endl;
    c.display();
    cout << "Rent for 3 days: " << c.calculateRent(3) << endl << endl;
    cout << "Bike Details" << endl;
    b.display();
    cout << "Rent for 3 days: " << b.calculateRent(3) << endl;
    return 0;
}