#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

int main() {
    vector<double> marks = {85.5, 92.0, 78.5, 88.0, 95.5};
    double sum = accumulate(marks.begin(), marks.end(), 0.0);
    double avg = sum / marks.size();

    sort(marks.begin(), marks.end());
    cout << "== Student Analytics ==" << endl;
    cout << "Average: " << avg << endl;
    cout << "Lowest: " << marks.front() << " | Highest: " << marks.back() << endl;
    return 0;
}
