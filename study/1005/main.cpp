#include <iostream>
#include <climits>

void shift(int *array, int n, int *data);

void calcDiff(const int *array, int n, const int *data);

using std::cout;
using std::endl;
using std::cin;

long min = INT_MAX;

int main() {
    int n = 0;
    cin >> n;
    int array[20];
    int data[20];

    for (int i = 0; i < n; ++i) {
        array[i] = 0;
        cin >> data[i];
    }
    array[n] = 0;
    shift(array, n, data);
    cout << min << endl;
    return 0;
}

void shift(int *array, int n, int *data) {
    array[0]++;
    for (int i = 0; i < n; ++i) {
        if (array[i] == 2) {
            array[i + 1]++;
            array[i] = 0;
        }
    }

    if (array[n] != 1) {
//        for (int i = 0; i < n; ++i) {
//            cout << array[i];
//        }
//        cout << endl;
        calcDiff(array, n, data);
        shift(array, n, data);
    }
}

void calcDiff(const int *array, int n, const int *data) {
    long firstHeap = 0;
    long secondHeap = 0;

    for (int i = 0; i < n; ++i) {
        if (array[i] == 0) {
            firstHeap += data[i];
        } else {
            secondHeap += data[i];
        }
    }

    long minHeap = labs(firstHeap - secondHeap);

    if (min > minHeap) {
        min = minHeap;
    }
}