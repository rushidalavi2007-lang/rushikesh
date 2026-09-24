#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class SafeArray {
private:
    T* data;
    int size;
public:
    SafeArray(int s) : size(s) {
        data = new T[size];
    }
    ~SafeArray() { delete[] data; }

    void set(int index, T val) {
        if (index < 0 || index >= size) throw out_of_range("Index Out of Bounds!");
        data[index] = val;
    }

    T get(int index) const {
        if (index < 0 || index >= size) throw out_of_range("Index Out of Bounds!");
        return data[index];
    }
};

int main() {
    try {
        SafeArray<double> arr(3);
        arr.set(0, 95.5);
        arr.set(1, 88.0);
        cout << "Index 0: " << arr.get(0) << endl;
        cout << "Triggering out of bounds check..." << endl;
        arr.get(5);
    } catch (const exception& e) {
        cout << "Caught Exception: " << e.what() << endl;
    }
    return 0;
}
