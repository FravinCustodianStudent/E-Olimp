#include <iostream>
using namespace std;

int main() {
	int s, k, a, b;
	int n = 0;
	int d;
	cin >> s >> k >> a >> b;
	if (a * s == b) {
		cout << s * k;
		return 0;
	}
	while (n < s * k) {
		if ((b - s * a) % (n - s * k) == 0) {
			d = (b - s * a) / (n - s * k);
			if (b - s >= d * n && a > d * k) {
				cout << n;
				return 0;
			}
		}
		n++;
	}
	cout << -1;
	return 0;
}