#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Library {
public:
    static void addBook(int id, string title) {
        ofstream out("books.txt", ios::app);
        out << id << " " << title << "\n";
        out.close();
    }

    static void showBooks() {
        ifstream in("books.txt");
        int id; string title;
        cout << "== Library Inventory ==" << endl;
        while (in >> id >> title) {
            cout << "Book ID: " << id << " | Title: " << title << endl;
        }
        in.close();
    }
};

int main() {
    Library::addBook(1, "OOP_Concepts");
    Library::addBook(2, "Data_Structures");
    Library::showBooks();
    return 0;
}
