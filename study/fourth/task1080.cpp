#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int result[n];
    result[0] = 0;
    for (int i = 1; i < n; ++i) {
        result[i] = -1;
    }

    int adjacencies_matrix[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            adjacencies_matrix[i][j] = 0;
        }
    }

    int neighbor;
    for (int i = 0; i < n; i++) {
        cin >> neighbor;
        while (neighbor) {
            neighbor--;
            adjacencies_matrix[i][neighbor] = 1;
            adjacencies_matrix[neighbor][i] = 1;
            cin >> neighbor;
        }
    }

    bool possibility = true;
    int country = 0;
    int next_wave = 0;
    vector<int> country_wave = {0};
    while (next_wave < n && possibility) {
        country = country_wave[next_wave++];
        for (int j = 0; j < n; j++) {
            if (adjacencies_matrix[country][j]) {
                if (result[j] == -1) {
                    country_wave.push_back(j);
                    result[j] = !result[country];
                } else {
                    if (result[j] == result[country]) {
                        possibility = false;
                        break;
                    }
                }
            }
        }
    }

    if (!possibility) {
        cout << -1;
    } else {
        for (int i = 0; i < n; i++) {
            cout << result[i];
        }
    }
    return 0;
}