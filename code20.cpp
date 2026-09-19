#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) { name = n; }
    void displayName() { cout << "Name: " << name << endl; }
};

class Student : virtual public Person {
public:
    Student() : Person("Unknown") {}
};

class Employee : virtual public Person {
public:
    Employee() : Person("Unknown") {}
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(string n) : Person(n), Student(), Employee() {}
};

int main() {
    TeachingAssistant ta("Riya");
    ta.displayName();
    return 0;
}