#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ofstream logOut("server.log");
    logOut << "INFO Server started\n";
    logOut << "ERROR Database connection failed\n";
    logOut << "CRITICAL Disk space low\n";
    logOut.close();

    ifstream logIn("server.log");
    string line;
    cout << "== Critical DevOps Events ==" << endl;
    while (getline(logIn, line)) {
        if (line.find("ERROR") != string::npos || line.find("CRITICAL") != string::npos) {
            cout << line << endl;
        }
    }
    logIn.close();
    return 0;
}
