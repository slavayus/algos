#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

int main() {

    ofstream dataFile;
    dataFile.open("data.txt");

    int allTests = 1;

    for (int j = 0; j < allTests; ++j) {
        int n = 110000+2;
        dataFile << n << endl;

        for (int i = 0; i < n; ++i) {
            dataFile << random() % 1000000 +1<< ' ' << random() % 1000000 +1<< endl;
        }
    }
    dataFile.close();
}
