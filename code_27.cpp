#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
    void display() const {
        cout << real << (imag >= 0 ? " + " : " - ") << (imag >= 0 ? imag : -imag) << "i\n";
    }
};

int main() {
    Complex c1(2, 3), c2(4, 5);
    Complex sum = c1 + c2;
    cout << "Sum: "; sum.display();
    return 0;
}