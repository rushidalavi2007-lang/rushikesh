#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    double marks;
    Student() : rollNo(0), marks(0.0) {}
    Student(int r, string n, double m) : rollNo(r), name(n), marks(m) {}

    void display() const {
        cout << "Roll: " << rollNo << " | Name: " << name << " | Marks: " << marks << endl;
    }
};

int main() {
    ofstream out("students.csv");
    out << "101,Rahul Patil,85.5\n";
    out << "102,Priya Sharma,92.0\n";
    out.close();

    ifstream in("students.csv");
    string line;
    cout << "== Student Records from CSV ==" << endl;
    while (getline(in, line)) {
        stringstream ss(line);
        string r, n, m;
        getline(ss, r, ',');
        getline(ss, n, ',');
        getline(ss, m, ',');
        Student s(stoi(r), n, stod(m));
        s.display();
    }
    in.close();
    return 0;
}
