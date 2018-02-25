#include <iostream>
#include <vector>

using namespace std;

int main() {

    int numberOfMembers;
    cin >> numberOfMembers;

    auto *right = new int[numberOfMembers];
    auto *down = new int[numberOfMembers];

    for (int i = 0; i < numberOfMembers; ++i) {
        cin >> right[i];
        cin >> down[i];
    }


    auto *roadLength = new long long[numberOfMembers];
    for (int i = 0; i < numberOfMembers; ++i) {
        roadLength[i] = 0;
    }


    for (int j = 0; j < numberOfMembers; ++j) {
        for (int i = j + 1; i < numberOfMembers; ++i) {
            long long length = abs(right[i] - right[j]) + abs(down[i] - down[j]);
            roadLength[i] += length;
            roadLength[j] += length;
        }
    }

    long long fullRoad = 0;
    for (int i = 0; i < numberOfMembers; ++i) {
        fullRoad += roadLength[i];
    }

    cout << fullRoad / (numberOfMembers*(numberOfMembers-1)) << endl;
}