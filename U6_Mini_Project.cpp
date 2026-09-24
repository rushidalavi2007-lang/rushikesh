#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    map<string, double> catalog;
    catalog["Laptop"] = 55000.0;
    catalog["Mouse"] = 500.0;

    vector<string> cart;
    cart.push_back("Laptop");
    cart.push_back("Mouse");

    double total = 0.0;
    cout << "== E-Commerce Cart Invoice ==" << endl;
    for (int i = 0; i < cart.size(); i++) {
        string item = cart[i];
        cout << item << " : Rs. " << catalog[item] << endl;
        total += catalog[item];
    }
    cout << "-----------------------" << endl;
    cout << "Total Amount: Rs. " << total << endl;
    return 0;
}
