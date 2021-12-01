#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int makeSimpleNumbers(int numb, vector<int>& dividers) {
    int divisor = 2;

    while (divisor * divisor <= numb) {
        if (numb % divisor == 0) {
            dividers.push_back(divisor);
            numb = numb / divisor;
        }
        else if (divisor == 2) divisor = 3;
        else divisor = divisor + 2;
    }
    dividers.push_back(numb);
    reverse(dividers.begin(), dividers.end());

    return 0;
}

double findTheSmallest(vector<vector<int> >& dividers) {
    double result_to_return = 1000000000000;
    for (auto& divider : dividers) {
        double result = 1;
        for (int i = 0; i < divider.size(); ++i) {
            vector<int> simpleNumbers = {
                    2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101,
                    103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
                    211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311 };
            result *= pow(simpleNumbers[i], divider[i] - 1);
        }

        if (result <= result_to_return) {
            result_to_return = result;
        }
    }
    return result_to_return;
}

void makeDividers(int k, vector<vector<int> >& dividers) {
    for (int i = k; i > 0; --i) {
        if (k % i == 0 & i >= k / i) {
            dividers.push_back({ i, k / i });
        }
        else if (k % i == 0 & i < k / i) {
            vector <int> _dividers(0);
            makeSimpleNumbers(k, _dividers);
            dividers.push_back(_dividers);
            break;
        }
    }
}

int main() {
    int k;
    cin >> k;

    vector<vector<int> > firstDividers(0);
    vector<vector<int> > secondDividers(0);

    makeDividers(2 * k, firstDividers);
    makeDividers(2 * k - 1, secondDividers);

    double k_2 = findTheSmallest(firstDividers);
    double k_2_minus_1 = findTheSmallest(secondDividers);

    if (k_2 <= k_2_minus_1) {
        cout << (long long int) k_2;
    }
    else {
        cout << (long long int) k_2_minus_1;
    }

    return 0;
}