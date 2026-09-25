#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() { cout << "Base destructor called\n"; }
};

class Derived : public Base {
public:
    ~Derived() override { cout << "Derived destructor called\n"; }
};

int main() {
    Base* ptr = new Derived();
    delete ptr;
    return 0;
}