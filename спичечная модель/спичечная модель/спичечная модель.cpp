﻿#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
//https://cpp.mazurok.com/matches-2/
int bit(int i, int n, int u)
{
    do
    {
        i = i + 1;
    } while (pow(i, u) < n);
    return i;
}


int main() {
    double n, result, p;//переменные для результата и количество кубиков,на всякий случай большой размерности
    long long int i = 0, g = 0;//объявляем переенные для разрядностей
    cin >> n;
    i = bit(i, n, 3);//находим разрядность куба
    if ((i * i * (i - 1)) >= n)//проверка третьего этапа
    {
        if (((i - 1) * (i - 1) * i) >= n)//проверка первого этапа и если правда,то решение первого этапа
        {
            double o = i - 1;
            result = 8 * o + 4 + 5 * o * (o - 1) * 2 + 3 * (o - 1) * 2 + 3 * o * (o - 1) * (o - 1) + 2 * (o - 1) * (o - 1);//результату присваем прошылй куб
            p = n - o * o * o;//количество оставшихся кубов
            g = bit(g, p, 2);//разрядность плоскости
            if (g == 1)//проверка разрядности на 1
                result += 8;//увеличение результата на 8 при разрядности 1
            else
                result += 8 + (g - 2) * 2 * 5 + 3 * ((g - 1) * (g - 1) - 1 - (g - 2) * 2);//увеличение результата по формуле
            for (long int i = 1; (g - 1) * (g - 1) + i <= p; i++)
            {
                if ((i == 1 || i == g) && g != 1)
                {
                    result += 5;
                }
                else if (g != 1)
                {
                    result += 3;
                }
            }

        }
        else//решение второго этапа
        {
            double o = i - 1;
            result = 8 * o + 4 + 5 * o * (o - 1) * 2 + 3 * (o - 1) * 2 + 3 * o * (o - 1) * (o - 1) + 2 * (o - 1) * (o - 1) + o * o * 3 + 5 + 2 * 2 * (o - 1);//результат по формуле+ещё достроеная на первом этапе стенка
            p = n - o * o * (o + 1);
            g = bit(g, p, 2);
            if (g == 1)
                result += 8;
            else
                result += 8 + (g - 2) * 2 * 5 + 3 * ((g - 1) * (g - 1) - 1 - (g - 2) * 2);
            for (long int i = 1; ((g - 1) * (g - 1) + i) <= p; i++)
            {
                if ((i == 1 || i == g) && g != 1)
                {
                    result += 5;
                }
                else if (g != 1)
                {
                    result += 3;
                }
            }
        }
    }
    else//решение третьего этапа
    {
        double o = i;
        result = 8 * (o - 1) + 4 + 5 * (o - 1) * (o - 1) * 2 + 3 * (o - 1) * 2 + 3 * (o - 1) * (o - 1) * (o - 1) + 2 * (o - 1) * (o - 1);//результат по формуле разрядности,только на высоту раную i-1
        p = n - (o - 1) * o * o;
        g = bit(g, p, 2);
        if (g == 1)
            result += 8;
        else
            result += 8 + (g - 2) * 2 * 5 + 3 * ((g - 1) * (g - 1) - 1 - (g - 2) * 2);
        for (long int i = 1; ((g - 1) * (g - 1) + i) <= p; i++)
        {
            if ((i == 1 || i == g) && g != 1)
            {
                result += 5;
            }
            else if (g != 1)
            {
                result += 3;
            }
        }
    }
    cout << result << endl;
    return 0;
}