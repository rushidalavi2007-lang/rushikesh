#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks[3];

public:
    Student(int r, string n, float m1, float m2, float m3) {
        rollNo = r;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    float calculateAverage() {
        return (marks[0] + marks[1] + marks[2]) / 3;
    }

    void displayResult() {
        float average = calculateAverage();
        char grade;

        if (average >= 90)
            grade = 'A';
        else if (average >= 75)
            grade = 'B';
        else if (average >= 60)
            grade = 'C';
        else if (average >= 40)
            grade = 'D';
        else
            grade = 'F';

        cout << "\nRoll No: " << rollNo;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks[0] << " "
             << marks[1] << " " << marks[2];
        cout << "\nAverage: " << average;
        
        if (average >= 40)
            cout << "\nResult: Pass";
        else
            cout << "\nResult: Fail";

        cout << "\nGrade: " << grade << endl;
    }
};

int main() {
    int rollNo;
    string name;
    float m1, m2, m3;

    for (int i = 1; i <= 3; i++) {
        cout << "\nEnter details of Student " << i << endl;

        cout << "Roll No: ";
        cin >> rollNo;

        cout << "Name: ";
        cin >> name;

        cout << "Enter 3 marks: ";
        cin >> m1 >> m2 >> m3;

        Student s(rollNo, name, m1, m2, m3);

        s.displayResult();
    }

    return 0;
}