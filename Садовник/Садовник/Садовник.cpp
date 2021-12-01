#include <iostream>
using namespace std;

int main() {
	int n, k;
	double waterPerTree = 0;
	cin >> n;
	int days = 0;
	while (waterPerTree <= 0.5) {
		waterPerTree += (double)1 / (n - days++);
	}
	k = n - days + 1;
	cout << k;
	return 0;
}