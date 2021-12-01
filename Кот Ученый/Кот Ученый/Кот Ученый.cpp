#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int l, n, k, count = 0;
    cin >> l >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 * x1 + y1 * y1 <= l * l || x2 * x2 + y2 * y2 <= l * l)
            count++;
        else
        {
            int a, b, c;
            int deltaX = x2 - x1;
            int deltaY = y2 - y1;
            a = deltaY;
            b = -deltaX;
            c = y1 * deltaX - x1 * deltaY;
            if (c * c <= l * l * (a * a + b * b) && (-c * b <= (b * b + a * a) * max(y2, y1) && -c * b >= (b * b + a * a) * min(y2, y1)))
                count++;
        }
    }
    cout << count / k + 1 << endl;
    return 0;
}