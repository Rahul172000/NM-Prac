#include <bits/stdc++.h>
using namespace std;

float u_cal(float u, int n)
{
    float temp = u;
    for (int i = 1; i < n; i++)
        temp = temp * (u + i);
    return temp;
}

int fact(int n)
{
    int f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}

int main()
{
    int n = 8;
    float x[] = {10, 20, 30, 40, 50, 60, 70, 80};

    float y[n][n];
    y[0][0] = 0.9848;
    y[1][0] = 0.9347;
    y[2][0] = 0.8660;
    y[3][0] = 0.7660;
    y[4][0] = 0.6428;
    y[5][0] = 0.5000;
    y[6][0] = 0.3420;
    y[7][0] = 0.1737;

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];
    }

    cout << "\nBackward difference table\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            cout << setw(4) << y[i][j]
                 << "\t";
        cout << endl;
    }

    float value = 73;

    float sum = y[n - 1][0];
    float u = (value - x[n - 1]) / n;
    for (int i = 1; i < n; i++)
    {
        sum = sum + (u_cal(u, i) * y[n - 1][i]) /
                        fact(i);
    }

    cout << "\n Value at " << value << " degrees is "
         << sum << endl;
    return 0;
}