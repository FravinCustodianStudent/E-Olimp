#include <iostream>  
using namespace std;
int main() {
    long m, n, p;
    cin >> m >> n;
    p = (m * n - (m + n - 1)) + 1;
    cout << p << endl;
    return 0;
}