#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::vector;

int main() {
    //считываем количество тестов
    int testCount;
    cin >> testCount;

    int k;
    int n;
    int countLargeTeam = 0;
    int duelCount;
    int personInCurrentTeam;
    int personInOneTeam;
    vector<int> answers;

    //Запускам алгоритм для каждого тестка
    for (int i = 0; i < testCount; ++i) {
        cin >> n;
        cin >> k;

        //Посчитали количество бойцов в одной команаде
        personInOneTeam = n / k;

        //Но не все команды могут получится с одинаковым коливеством бойцов.
        //Вычисляем количество команд, в составе которых больше бойцов
        countLargeTeam = n - (personInOneTeam) * k;

        //Количество схваток между бойцами
        duelCount = 0;

        //Берем текущую команду и умножаем на количество оставшихся бойцов.
        //Постоянно уменьшаем количество бойцов, чтобы дважды не считать один и тот же бой.
        while (n > 0) {
            //Пока не закончились команды, в составе которых больше бойцов, вычисляем число бойцов в текущей команде
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