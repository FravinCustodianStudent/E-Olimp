#include <iostream>
using namespace std;
int main() {
    int vertSize;
    int horSize;
    int firstNumber;
    int lastNumber;
    cin >> horSize >> vertSize >> firstNumber >> lastNumber;
    if (firstNumber > lastNumber) {
        swap(firstNumber, lastNumber);
    }
    int firstNumberx = (firstNumber - 1) % (2 * horSize) + 1;
    int firstNumbery = (firstNumber - 1) / (2 * horSize) + 1;
    int lastNumberx = (lastNumber - 1) % (2 * horSize) + 1;
    int lastNumbery = (lastNumber - 1) / (2 * horSize) + 1;
    int Search[2 * horSize];
    Search[firstNumberx - 1] = 0;
    int step = 1;
    for (int i = firstNumberx - 2; i >= 0; i--) {
        Search[i] = step++;

    }
    step = 1;
    for (int i = firstNumberx; i < 2 * horSize; i++) {
        Search[i] = step++;
    }
    for (int j = firstNumbery; j < lastNumbery; j++) {
        for (int i = 1; i < 2 * horSize; i += 2) {
            Search[i - 1] = Search[i] + 1;
            Search[i] += 2;
            if (((i - 2) >= 0) && (Search[i] < Search[i - 2])) {
                Search[i - 2] = Search[i];
            }
        }
    }
    cout << Search[lastNumberx - 1] << endl;
    return 0;
}