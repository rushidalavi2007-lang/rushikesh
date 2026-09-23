#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override { return 3.14159 * radius * radius; }
    void draw() const override { cout << "Drawing Circle with radius " << radius << endl; }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() const override { return length * width; }
    void draw() const override { cout << "Drawing Rectangle " << length << "x" << width << endl; }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    cout << "== CAD Shape System ==" << endl;
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->area() << endl;
        delete shapes[i];
    }
    return 0;
}
