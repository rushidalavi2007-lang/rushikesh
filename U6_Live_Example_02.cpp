#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main() {
    vector<string> ips = {"192.168.1.1", "192.168.1.2", "192.168.1.1", "192.168.1.3", "192.168.1.1"};
    map<string, int> freq;

    for (int i = 0; i < ips.size(); i++) {
        freq[ips[i]]++;
    }

    cout << "== IP Request Frequencies ==" << endl;
    for (auto it = freq.begin(); it != freq.end(); it++) {
        cout << it->first << ": " << it->second << " requests" << endl;
    }
    return 0;
}
