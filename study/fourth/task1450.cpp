#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, m, s, f;

struct point {
    vector<int> neighbour_points;
    vector<int> price;
};

int countWay(int current, int *max_way, const point *points) {
    int &result = max_way[current];
    int temp;
    int max_profit = INT_MIN;

    if (current != f && result == -1) {
        for (int i = 0; i < points[current].neighbour_points.size(); ++i) {
            temp = countWay(points[current].neighbour_points[i], max_way, points);
            if (temp != -2) {
                temp += points[current].price[i];
                max_profit = max(max_profit, temp);
            }
        }
        result = max(-2, max_profit);
    } else {
        if (current == f) {
            result = 0;
        }
    }

    return result;
}


int main() {
    int a, b;
    int c, result;

    cin >> n;
    cin >> m;
    int max_way[n + 1];
    for (int i = 0; i < n + 1; ++i) {
        max_way[i] = -1;
    }

    struct point points[n + 1];

    for (int i = 0; i < m; ++i) {
        cin >> a;
        cin >> b;
        cin >> c;
        points[a].price.insert(points[a].price.end(), c);
        points[a].neighbour_points.insert(points[a].neighbour_points.end(), b);
    }
    cin >> s;
    cin >> f;
    result = countWay(s, max_way, points);
    if (result == -2) {
        cout << "No solution";
    } else {
        cout << result;
    }
}