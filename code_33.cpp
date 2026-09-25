#include <iostream>
using namespace std;

class Base {
public:
    virtual void display() const { cout << "Base object\n"; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void display() const override { cout << "Derived object\n"; }
};

void passByValue(Base b) { b.display(); }
void passByReference(const Base& b) { b.display(); }

int main() {
    Derived d;
    cout << "By value (slicing occurs): "; passByValue(d);
    cout << "By reference (polymorphism preserved): "; passByReference(d);
    return 0;
}