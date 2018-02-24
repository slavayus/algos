#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;

int main() {

    int inputData[20];
    int numberOfRocks;
    cin >> numberOfRocks;
    int data;
    for (int i = 0; i < numberOfRocks; i++) {
        cin >> data;
        inputData[i] = data;
    }


    int firsHeap = 0;
    int secondHeap = 0;
    int maxWeight;
    int coeffOfMaxWeight;
    for (int i = 0; i < numberOfRocks; i++) {

        coeffOfMaxWeight = 0;
        maxWeight = inputData[coeffOfMaxWeight];

        for (int j = 1; j < numberOfRocks; ++j) {
            if (maxWeight < inputData[j]) {
                coeffOfMaxWeight = j;
                maxWeight = inputData[coeffOfMaxWeight];
            }
        }


        if (firsHeap < secondHeap) {
            firsHeap += maxWeight;
        } else {
            secondHeap += maxWeight;
        }
        inputData[coeffOfMaxWeight] = -1;
    }

    cout << abs(firsHeap - secondHeap) << endl;
}
