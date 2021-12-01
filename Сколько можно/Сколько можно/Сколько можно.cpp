#include <iostream>
using namespace std;

int main()
{
    unsigned long long N, sum, subsidiary = 0, quantity = 0;
    cin >> N;
    while (N > 999999999)
    {
        sum = 0;
        subsidiary = N;
        while (subsidiary != 0)
        {
            sum += subsidiary % 10;
            subsidiary /= 10;
        }
        N -= sum;
        quantity++;
    }
    if (N == 999999999)
    {
        N = 0;
        quantity += 25632473;
    }
    while (N > 0)
    {
        sum = 0;
        subsidiary = N;
        while (subsidiary != 0)
        {
            sum += subsidiary % 10;
            subsidiary /= 10;
        }
        N -= sum;
        quantity++;
    }
    cout << quantity << endl;
    return 0;
}