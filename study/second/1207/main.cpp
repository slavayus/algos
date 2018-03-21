#include <iostream>

using namespace std;

struct dot {
    long x;
    long y;
};

void quickSort(float *tan, dot *dots, int start, int end);

int main() {
    int k = 0;
    cin >> k;

    auto dots = new struct dot[k];
    auto originalInputData = new struct dot[k];

    long x;
    long y;
    for (int i = 0; i < k; i++) {
        cin >> x;
        cin >> y;

        dots[i].x = x;
        dots[i].y = y;
        originalInputData[i].x = x;
        originalInputData[i].y = y;
    }

    auto minDot = dots[0];
    int index = 0;
    for (int i = 0; i < k; i++) {
        if (minDot.x > dots[i].x) {
            minDot = dots[i];
            index = i;
        }
    }

    k--;
    for (int i = index; i < k; i++) {
        dots[i] = dots[i + 1];
    }


    auto tan = new float[k];
    for (int i = 0; i < k; i++) {
        tan[i] = ((float) (dots[i].y - minDot.y)) / ((float) (dots[i].x - minDot.x));
    }

    quickSort(tan, dots, 0, k - 1);

    cout << index + 1 << " ";
    auto dot = dots[k / 2];
    for (int i = 0; i < k + 1; i++) {
        if (dot.x == originalInputData[i].x && dot.y == originalInputData[i].y) {
            cout << i + 1 << endl;
            break;
        }
    }


}

void quickSort(float *tan, dot *dots, int start, int end) {
    float middle = tan[(start + end) / 2];
    int i = start;
    int j = end;
    do {
        while (tan[i] > middle) {
            i++;
        }
        while (tan[j] < middle) {
            j--;
        }
        if (i <= j) {
            float temp = tan[i];
            tan[i] = tan[j];
            tan[j] = temp;

            auto dot = dots[i];
            dots[i] = dots[j];
            dots[j] = dot;
            i++;
            j--;
        }
    } while (i < j);

    if (j > start) {
        quickSort(tan, dots, start, j);
    }
    if (i < end) {
        quickSort(tan, dots, i, end);
    }
}