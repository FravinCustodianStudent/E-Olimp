#include <iostream>
#include <cstring>
using namespace std;

int parse(char digit) {
	int result;
	switch (digit) {
	case 'I': result = 1; break;
	case 'V': result = 5; break;
	case 'X': result = 10; break;
	case 'L': result = 50; break;
	case 'C': result = 100; break;
	case 'D': result = 500; break;
	case 'M': result = 1000; break;
	default: result = 0;
	}
	return result;
}

int parse(char* number) {
	int result = 0, previous = parse(number[0]), current;
	for (int i = 1; (current = parse(number[i])) != 0; i++) {
		result += previous < current ? -previous : previous;
		previous = current;
	}
	result += previous;
	return result;
}

void print(int number) {
	char result[1000]{ '\0' };
	const int values[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	const char* symbols[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
	int counter = sizeof(symbols) / sizeof(symbols[0]) - 1;
	while (counter >= 0) {
		while (number >= values[counter]) {
			number -= values[counter];
			strcat(result, symbols[counter]);
		}
		counter--;
	}
	cout << result << endl;
}

int main() {
	char line[1000];
	cin >> line;
	char* a = strtok(line, "+");
	char* b = strtok(NULL, "");
	print(parse(a) + parse(b));
	return 0;
}