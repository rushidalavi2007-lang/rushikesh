#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() const { cout << "Animal sound\n"; }
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    void sound() const override { cout << "Dog barks\n"; }
};

class Cat : public Animal {
public:
    void sound() const override { cout << "Cat meows\n"; }
};

int main() {
    Dog dog; Cat cat;
    Animal* ptr = &dog; ptr->sound();
    ptr = &cat; ptr->sound();
    return 0;
}