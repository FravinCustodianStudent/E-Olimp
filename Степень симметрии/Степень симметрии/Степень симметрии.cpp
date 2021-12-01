#include "string"
#include "cstring"
#include "iostream"
using namespace std;
int main() {
    string str;
    int a = 0, i, d, w;
    getline(cin, str);
    d = str.length();
    w = d / 2;
    if (d % 2 != 0)a++;
    for (i = 0; i < w; i++)
        if (str[i] == str[d - i - 1]) a++;
    cout << a << endl;
}