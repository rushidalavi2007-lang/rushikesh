#include <iostream>
#include <string>
using namespace std;

class University {
public:
    class Department {
        string name;
    public:
        Department(string n) { name = n; }
        void display() { cout << "Department: " << name << endl; }
    };
};

int main() {
    University::Department dept("Artificial Intelligence and Data Science");
    dept.display();
    return 0;
}