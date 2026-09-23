#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Validator {
public:
    bool validate(int marks) const {
        return marks >= 0 && marks <= 100;
    }

    bool validate(double amount) const {
        return amount > 0.0 && amount <= 1000000.0;
    }

    bool validate(const string& name) const {
        if (name.empty()) return false;
        for (int i = 0; i < name.length(); i++) {
            if (!isalpha(name[i]) && name[i] != ' ') return false;
        }
        return true;
    }
};

int main() {
    Validator v;
    cout << boolalpha;
    cout << "== Input Validation Service ==" << endl;
    cout << "Marks 88 valid: " << v.validate(88) << endl;
    cout << "Amount 4500.50 valid: " << v.validate(4500.50) << endl;
    cout << "Name 'Priya Sharma' valid: " << v.validate("Priya Sharma") << endl;
    return 0;
}
