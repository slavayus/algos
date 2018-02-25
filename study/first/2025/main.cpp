#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    int testCount;
    cin >> testCount;

    int k;
    int n;
    int countLargeTeam = 0;
    int duelCount;
    int personInCurrentTeam;
    int personInOneTeam;
    vector<int> answers;

    for (int i = 0; i < testCount; ++i) {
        cin >> n;
        cin >> k;

        personInOneTeam = n / k;

        countLargeTeam = n - (personInOneTeam) * k;

        duelCount = 0;

        while (n > 0) {
            personInCurrentTeam = countLargeTeam > 0 ? personInOneTeam + 1 : personInOneTeam;

            --countLargeTeam;

            n -= personInCurrentTeam;

            duelCount += personInCurrentTeam * n;
        }
        answers.push_back(duelCount);
    }

    for (int answer : answers) {
        cout << answer << endl;
    }

    return 0;
}