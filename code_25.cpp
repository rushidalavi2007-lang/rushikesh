#include <iostream>
using namespace std;

int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }
int add(int a, int b, int c) { return a + b + c; }

int main() {
    cout << "Sum (int, int): " << add(10, 20) << '\n';
    cout << "Sum (double, double): " << add(2.5, 3.7) << '\n';
    cout << "Sum (int, int, int): " << add(10, 20, 30) << '\n';
    return 0;
}