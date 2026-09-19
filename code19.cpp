#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double len, wid;
public:
    Rectangle(double l, double w) : len(l), wid(w) {}
    double area() override { return len * wid; }
};

class Circle : public Shape {
    double rad;
public:
    Circle(double r) : rad(r) {}
    double area() override { return 3.14159 * rad * rad; }
};

int main() {
    Rectangle r(5.0, 3.0);
    Circle c(2.0);
    cout << "Rectangle Area: " << r.area() << endl;
    cout << "Circle Area: " << c.area() << endl;
    return 0;
}