#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int totalDays;
    int presentDays;
public:
    Student(int r, string n) : rollNo(r), name(n), totalDays(0), presentDays(0) {}

    void markAttendance(bool isPresent) {
        totalDays++;
        if (isPresent) presentDays++;
    }

    double getAttendancePercentage() const {
        if (totalDays == 0) return 0.0;
        return (presentDays * 100.0) / totalDays;
    }

    void checkDefaulter() const {
        if (getAttendancePercentage() < 75.0) {
            cout << " [STATUS: Defaulter - Attendance below 75%]" << endl;
        } else {
            cout << " [STATUS: Eligible]" << endl;
        }
    }

    void display() const {
        cout << "Roll: " << rollNo 
             << " | Name: " << name 
             << " | Attendance: " << getAttendancePercentage() << "%";
        checkDefaulter();
    }
};

int main() {
    Student s1(101, "Rahul");
    Student s2(102, "Priya");

    s1.markAttendance(true);
    s1.markAttendance(false);
    s1.markAttendance(false);

    s2.markAttendance(true);
    s2.markAttendance(true);
    s2.markAttendance(true);

    cout << "== Attendance Report ==" << endl;
    s1.display();
    s2.display();
    return 0;
}
