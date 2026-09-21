#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual double calculateSalary() = 0;
    void displayBasicDetails() {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class PermanentEmployee : public Employee {
    double basic, allowance;
public:
    PermanentEmployee(int i, string n, double b, double a) : Employee(i, n), basic(b), allowance(a) {}
    double calculateSalary() override { return basic + allowance; }
};

class ContractEmployee : public Employee {
    double hourlyRate;
    int hours;
public:
    ContractEmployee(int i, string n, double rate, int h) : Employee(i, n), hourlyRate(rate), hours(h) {}
    double calculateSalary() override { return hourlyRate * hours; }
};

void displayPaySlip(Employee& emp) {
    emp.displayBasicDetails();
    cout << "Salary: " << emp.calculateSalary() << endl << endl;
}

int main() {
    PermanentEmployee p(101, "Asha", 40000.0, 8000.0);
    ContractEmployee c(102, "Vikas", 500.0, 80);
    displayPaySlip(p);
    displayPaySlip(c);
    return 0;
}