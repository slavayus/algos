#include <iostream>
#include <vector>
#include <cmath>


using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ios_base;

int main() {
    cout.setf(ios_base::fixed);
    cout.precision(4);
    long double number;

    vector<long double> data;

    while (cin >> number) {
        data.push_back(sqrt(number));
    }

    for (int i = data.size()-1; i >= 0; i--) {
        cout << data[i] << endl;
    }
}
