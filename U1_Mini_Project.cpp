#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SmartDevice {
private:
    string deviceId;
    string location;
    bool status;
public:
    SmartDevice(string id, string loc, bool s = false) 
        : deviceId(id), location(loc), status(s) {}

    void switchState(bool s) { status = s; }

    void displayDashboard() const {
        cout << "Device: " << deviceId 
             << " | Location: " << location 
             << " | Status: " << (status ? "ON" : "OFF") << endl;
    }
};

int main() {
    vector<SmartDevice> home;
    home.push_back(SmartDevice("D101", "Living Room Light", true));
    home.push_back(SmartDevice("D102", "Bedroom AC", false));
    home.push_back(SmartDevice("D103", "Main Door Lock", true));

    cout << "== Smart Home Dashboard ==" << endl;
    for (int i = 0; i < home.size(); i++) {
        home[i].displayDashboard();
    }
    return 0;
}
