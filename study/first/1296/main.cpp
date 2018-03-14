#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    int countAlpha;
    cin >> countAlpha;

    vector<int> inputData;

    int currentNumber;
    for (int i = 0; i < countAlpha; ++i) {
        cin >> currentNumber;
        inputData.push_back(currentNumber);
    }


    long long currentPotential = 0;
    long long maxPotential = 0;

    //Подсчитываем сумму и каждый раз проверяем, является ли она уже больше найденной.
    //Если нашли сумму больше, то запоминаем ее.
    //Если при подсчете суммы получилось так, что мы ушли в минус, то начинаем подсчет суммы с нуля.
    for (int j = 0; j < countAlpha; ++j) {

        currentPotential += inputData[j];
        if (currentPotential < 0) {
            currentPotential = 0;
        }
        if (currentPotential > maxPotential) {
            maxPotential = currentPotential;
        }

    }
    cout << maxPotential;
}