#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle {
protected:
    string vehicleId;
    string registrationNumber;
    double fuelLevel;
public:
    Vehicle(string vid, string reg) 
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}

    virtual void displayInfo() const {
        cout << "ID: " << vehicleId << " | Reg: " << registrationNumber << " | Fuel: " << fuelLevel << "%" << endl;
    }
    virtual ~Vehicle() {}
};

class Truck : public Vehicle {
private:
    double cargoCapacity;
public:
    Truck(string vid, string reg, double cap) : Vehicle(vid, reg), cargoCapacity(cap) {}

    void displayInfo() const override {
        cout << "Truck | ";
        Vehicle::displayInfo();
    }
};

class Bike : public Vehicle {
private:
    bool hasDeliveryBox;
public:
    Bike(string vid, string reg, bool box) : Vehicle(vid, reg), hasDeliveryBox(box) {}

    void displayInfo() const override {
        cout << "Bike | ";
        Vehicle::displayInfo();
    }
};

int main() {
    vector<Vehicle*> fleet;
    fleet.push_back(new Truck("V001", "MH12-AB-1234", 10.5));
    fleet.push_back(new Bike("V002", "MH12-EF-9012", true));

    cout << "== Fleet Status ==" << endl;
    for (int i = 0; i < fleet.size(); i++) {
        fleet[i]->displayInfo();
        delete fleet[i];
    }
    return 0;
}
