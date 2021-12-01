#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
    int m, n;
    long long X[100][100];
    string ans;
    cin >> n >> m;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++)cin >> X[i][j];
    }
    for (int i = 1; i < n; i++)X[i][0] = X[i][0] + X[i - 1][0];
    for (int j = 1; j < m; j++)X[0][j] = X[0][j] + X[0][j - 1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) X[i][j] = X[i][j] + max(X[i - 1][j], X[i][j - 1]);
    }
    int k = n - 1, t = m - 1;
    while (k > 0 || t > 0) {
        if (k > 0 && t > 0) {
            if (X[k - 1][t] > X[k][t - 1]) {
                ans += "F";
                k--;
            }
            else {
                ans += "R";
                t--;
            }
        }
        else if (k == 0) {
            ans += "R";
            t--;
        }
        else if (t == 0) {
            ans += "F";
            k--;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}