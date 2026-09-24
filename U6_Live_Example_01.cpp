#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Employee {
    string name;
    int age;
    double salary;
};

int main() {
    vector<Employee> staff = {{"Alice", 30, 70000}, {"Bob", 25, 50000}};
    map<string, double> salaryLookup;

    for (int i = 0; i < staff.size(); i++) {
        salaryLookup[staff[i].name] = staff[i].salary;
    }

    cout << "== STL Map Salary Lookup ==" << endl;
    cout << "Bob's Salary: Rs. " << salaryLookup["Bob"] << endl;
    return 0;
}
