﻿
#include <iostream>
#include <iomanip>
#include "tset.h"

using namespace std;

int main()
{
    int n, m, k, count;

    cout << "Sieve of Eratosthenes (Решето Эратосфена)." << endl;
    cout << "Введите верхнюю границу целых значений: ";
    cin >> n;
    TSet s(n + 1);
    for (m = 2; m <= n; m++)
        s.InsElem(m);
    for (m = 2; m * m <= n; m++)
        if (s.IsMember(m))
            for (k = 2 * m; k <= n; k += m)
                if (s.IsMember(k))
                    s.DelElem(k);
    cout << endl << "Печать множества некратных чисел: " << endl << s << endl;
    cout << endl << "Печать простых чисел." << endl;
    count = 0;
    k = 1;
    for (m = 2; m <= n; m++)
        if (s.IsMember(m))
        {
            count++;
            cout << setw(3) << m << " ";
            if (k++ % 10 == 0)
                cout << endl;
        }
    cout << endl;
    cout << "В первых " << n << " числах " << count << " простых." << endl;
    system("PAUSE");
}
