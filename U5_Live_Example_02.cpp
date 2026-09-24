#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
void sortItems(vector<T>& items) {
    for (int i = 0; i < items.size(); i++) {
        for (int j = i + 1; j < items.size(); j++) {
            if (items[j] < items[i]) {
                T temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

template <typename T>
void printItems(const vector<T>& items) {
    for (int i = 0; i < items.size(); i++) cout << items[i] << " ";
    cout << endl;
}

int main() {
    vector<int> nums;
    nums.push_back(50); nums.push_back(10); nums.push_back(30);
    sortItems(nums);
    cout << "== Sorted Numbers ==" << endl;
    printItems(nums);

    vector<string> names;
    names.push_back("Pune"); names.push_back("Mumbai"); names.push_back("Nashik");
    sortItems(names);
    cout << "== Sorted Cities ==" << endl;
    printItems(names);
    return 0;
}
