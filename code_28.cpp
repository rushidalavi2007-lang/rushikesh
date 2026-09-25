#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    explicit Distance(int m) : meters(m) {}
    bool operator>(const Distance& other) const {
        return meters > other.meters;
    }
    void display() const { cout << meters << " meters\n"; }
};

int main() {
    Distance d1(120), d2(90);
    if (d1 > d2) cout << "d1 is greater than d2\n";
    else cout << "d1 is not greater than d2\n";
    return 0;
}