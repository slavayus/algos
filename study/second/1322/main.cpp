#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &, vector<int> &, int, int);

int main() {
    int k = 0;
    cin >> k;
    vector<int> inputData;
    vector<int> indexOfInputData;

    int currentInput;
    for (int i = 0; i < k; ++i) {
        cin >> currentInput;
        inputData.push_back(currentInput);
        indexOfInputData.push_back(i + 1);
    }

    quickSort(indexOfInputData, inputData, 0, k - 1);

    int end = k-1;
    while (inputData[0] != 0) {
        for (int j = end; j >= 0; --j) {
            if (inputData[j] != 0) {
                cout << indexOfInputData[j] << ' ';
                inputData[j]--;
            } else {
                end = j-1;
                break;
            }
        }
    }
}

void quickSort(vector<int> &indexOfInputData, vector<int> &inputData, int start, int end) {
    int middle = (start + end) / 2;
    int i = start;
    int j = end;
    do {
        while (inputData[middle] < inputData[i]) {
            i++;
        }
        while (inputData[middle] > inputData[j]) {
            j--;
        }
        if (i <= j) {
            swap(inputData[j], inputData[i]);
            swap(indexOfInputData[i], indexOfInputData[j]);
            i++;
            j--;
        }
    } while (i < j);


    if (i < end) {
        quickSort(indexOfInputData, inputData, i, end);
    }

    if (j > start) {
        quickSort(indexOfInputData, inputData, start, j);
    }
}