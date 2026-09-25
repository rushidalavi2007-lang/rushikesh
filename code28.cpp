#include <iostream>
using namespace std;

class Counter {
private:
    int value;
public:
    explicit Counter(int initialValue = 0) : value(initialValue) {}

    // Prefix increment
    Counter& operator++() {
        ++value;
        return *this;
    }

    // Postfix increment
    Counter operator++(int) {
        Counter old = *this;
        ++value;
        return old;
    }

    void display() const {
        cout << value << '\n';
    }
};

int main() {
    Counter counter(5);

    cout << "After prefix increment: ";
    ++counter;
    counter.display();

    cout << "Value returned by postfix increment: ";
    Counter oldValue = counter++;
    oldValue.display();

    cout << "Counter after postfix increment: ";
    counter.display();

    return 0;
}