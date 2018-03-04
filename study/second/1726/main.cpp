#include <iostream>

void quickSort(unsigned long *data, long long start, long long end);

using namespace std;

int main() {

    long long numberOfMembers;
    cin >> numberOfMembers;

    auto *right = new unsigned long[numberOfMembers];
    auto *down = new unsigned long[numberOfMembers];

    for (long long i = 0; i < numberOfMembers; ++i) {
        cin >> right[i];
        cin >> down[i];
    }

    quickSort(right, 0, numberOfMembers - 1);
    quickSort(down, 0, numberOfMembers - 1);

    unsigned long long int length = 0;
    for (long long i = 0; i < numberOfMembers - 1; ++i) {
        length += (right[i + 1] - right[i] + down[i + 1] - down[i]) * (i + 1) * (numberOfMembers - i - 1);
    }

    cout << (length * 2) / (numberOfMembers * (numberOfMembers - 1)) << endl;

    return 0;
}

void quickSort(unsigned long *data, long long start, long long end) {

    long long i = start;
    long long j = end;

    unsigned long middle = data[(start + end) / 2];

    do {
        while (data[i] < middle) {
            i++;
        }
        while (data[j] > middle) {
            j--;
        }
        if (i <= j) {
            swap(data[i++], data[j--]);
        }
    } while (i <= j);

    if (i < end) {
        quickSort(data, i, end);
    }

    if (j > start) {
        quickSort(data, start, j);
    }
}