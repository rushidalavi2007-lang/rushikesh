#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) { name = n; }
};

class Student : public Person {
private:
    int rollNumber;
public:
    Student(string n, int r) : Person(n) { rollNumber = r; }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
    }
};

int main() {
    Student s("Kiran", 24);
    s.display();
    return 0;
}