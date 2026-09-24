#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int topIndex;
    int capacity;
public:
    Stack(int cap) : capacity(cap), topIndex(-1) {
        arr = new T[capacity];
    }
    ~Stack() { delete[] arr; }

    void push(T val) {
        if (topIndex == capacity - 1) throw overflow_error("Stack Overflow");
        arr[++topIndex] = val;
    }

    T pop() {
        if (topIndex == -1) throw underflow_error("Stack Underflow");
        return arr[topIndex--];
    }

    void display() const {
        for (int i = topIndex; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    try {
        Stack<int> s(5);
        s.push(10); s.push(20); s.push(30);
        cout << "== Template Stack ==" << endl;
        s.display();
        cout << "Popped: " << s.pop() << endl;
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
