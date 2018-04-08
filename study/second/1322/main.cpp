#include <iostream>

using namespace std;

int main() {
    string ALL_CHARS;
    ALL_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";

    int k;
    cin >> k;
    string inputData;
    cin >> inputData;
    auto inputCharsIndex = new int[inputData.length()];

    int currIndex = 0;
    for (char i : ALL_CHARS) {
        for (int j = 0; j < inputData.length(); j++) {
            if (i == inputData[j]) {
                inputCharsIndex[j] = currIndex++;
            }
            if (currIndex == inputData.length()) {
                break;
            }
        }
        if (currIndex == inputData.length()) {
            break;
        }
    }

    int currPos = inputCharsIndex[k - 1];
    string answer;
    answer += (inputData[k - 1]);
    for (int i = 0; i < inputData.length() - 1; i++) {
        answer += (inputData[currPos]);
        currPos = inputCharsIndex[currPos];
    }
    for (auto l = static_cast<int>(answer.length() - 1); l >= 0; --l) {
        cout<<answer[l];
    }

    return 0;
}