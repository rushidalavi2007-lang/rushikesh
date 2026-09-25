#include <iostream>
using namespace std;

class Counter {
    int value;
public:
    explicit Counter(int v = 0) : value(v) {}
    Counter operator-() const { return Counter(-value); }
    Counter& operator++() { ++value; return *this; }
    Counter operator++(int) { Counter old = *this; ++value; return old; }
    void display() const { cout << "Value: " << value << '\n'; }
};

int main() {
    Counter c(10);
    Counter neg = -c;
    cout << "Negated: "; neg.display();
    ++c;
    cout << "Prefix ++: "; c.display();
    c++;
    cout << "Postfix ++: "; c.display();
    return 0;
}