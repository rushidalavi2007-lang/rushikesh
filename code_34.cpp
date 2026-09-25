#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(move(n)) {}
    virtual double calculateSalary() const = 0;
    virtual ~Employee() = default;
    void printInfo() const { cout << "ID: " << id << " | Name: " << name; }
};

class PermanentEmployee : public Employee {
    double basic, allowance;
public:
    PermanentEmployee(int i, string n, double b, double a)
        : Employee(i, move(n)), basic(b), allowance(a) {}
    double calculateSalary() const override { return basic + allowance; }
};

int main() {
    PermanentEmployee emp(101, "Asha", 40000.0, 8000.0);
    emp.printInfo();
    cout << " | Total Salary: Rs. " << emp.calculateSalary() << '\n';
    return 0;
}