#include <iostream>
#include <memory>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void displayName() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
    double l, w;
public:
    Rectangle(double len, double wid) : l(len), w(wid) {}
    double area() const override { return l * w; }
    void displayName() const override { cout << "Rectangle"; }
};

class Circle : public Shape {
    double r;
public:
    explicit Circle(double rad) : r(rad) {}
    double area() const override { return 3.14159 * r * r; }
    void displayName() const override { cout << "Circle"; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.push_back(make_unique<Rectangle>(5.0, 3.0));
    shapes.push_back(make_unique<Circle>(2.0));

    for (const auto& s : shapes) {
        s->displayName();
        cout << " Area: " << s->area() << '\n';
    }
    return 0;
}