#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    friend Complex operator+(int val, const Complex& c);
    void display() const { cout << real << " + " << imag << "i\n"; }
};

Complex operator+(int val, const Complex& c) {
    return Complex(val + c.real, c.imag);
}

int main() {
    Complex c(2, 3);
    Complex res = 10 + c;
    cout << "Result: "; res.display();
    return 0;
}