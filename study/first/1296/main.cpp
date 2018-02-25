#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    int countAlpha;
    cin >> countAlpha;

    vector<int> inputData;

    int currentNumber;
    for (int i = 0; i < countAlpha; ++i) {
        cin >> currentNumber;
        inputData.push_back(currentNumber);
    }


    long long currentPotential = 0;
    long long maxPotential = 0;
    int start = 0;

    for (int j = 0; j < countAlpha; ++j) {

        currentPotential += inputData[j];
        if (currentPotential < 0) {
            currentPotential = 0;
            start = j;
        }
        if (currentPotential > maxPotential && start != j) {
            maxPotential = currentPotential;
        }

    }
    cout << maxPotential;
}