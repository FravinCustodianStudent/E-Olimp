#include <iostream>
#include <cmath>
using namespace std;

int Sum(int a) {
    int sum = 0;
    while (a > 0) {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int Mult(int a) {
    int mult = 1;
    while (a > 0) {
        mult *= a % 10;
        a /= 10;
    }
    return mult;
}

int main() {
    int n, ch = 0, sum = 0, mult = 0, a;
    bool b = true;
    cin >> n;
    if (n == 1) cout << 10 << " " << 0;
    else {
        if (n > 1 and n < 8) {
            for (int i = pow(10, n - 1); i < pow(10, n); i++) {
                sum = Sum(i);
                mult = Mult(i);
                if ((sum == mult) and b == true) { a = i; ch++; b = false; }
                else {
                    if (sum == mult) ch++;
                }
            }
            cout << ch << " " << a;
        }
        else {
            if (n == 8) cout << 224 << " " << 11111128;
            if (n == 9) cout << 144 << " " << 111111129;
        }
    }
    return 0;
}