#include <omp.h>
#include <stdio.h>
#include <iostream>
#include <chrono>
using namespace std;

int main()
{
    int l1, c1;
    int l2, c2;
    cin >> l1 >> c1;
    cin >> l2 >> c2;
    int a[l1][c1];
    int b[l2][c2];
    int c[l1][c2];

    for (int i = 0; i < c1; i++)
    {
        for (int j = 0; j < c1; j++)
        {
            // cin >> a[i][j];
            a[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < l2; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            // cin >> b[i][j];
            b[i][j] = rand() % 10;
        }
    }

    auto start = chrono::steady_clock::now();
    
    // #pragma omp parallel for
    for (int i = 0; i < l1; i++)
    {
        // #pragma omp parallel for
        for (int j = 0; j < c2; j++)
        {
            // #pragma omp parallel for
            for (int k = 0; k < l2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    auto end = chrono::steady_clock::now();

    // for (int i = 0; i < l1; i++)
    // {
    //     for (int j = 0; j < c2; j++)
    //     {
    //         cout << c[i][j] <<" ";
    //     }
    //     cout << endl;
    // }
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << endl;
}
