#include <iostream>
#include <climits>

void shift(int *array, int *data);

void calcDiff(const int *array, const int *data);

using std::cout;
using std::endl;
using std::cin;

long min = INT_MAX;

int n = 0;

int main() {
    cin >> n;
    int array[25];
    int data[25];

    for (int i = 0; i < n; ++i) {
        array[i] = 0;
        cin >> data[i];
    }
    array[n] = 0;
    shift(array, data);
    cout << min << endl;
    return 0;
}

void shift(int *array, int *data) {
    array[0]++;
    for (int i = 0; i < n; ++i) {
        if (array[i] == 2) {
            array[i + 1]++;
            array[i] = 0;
        } else {
            break;
        }
    }

    if (array[n] != 1) {
        calcDiff(array, data);
        shift(array, data);
    }
}

void calcDiff(const int *array, const int *data) {
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