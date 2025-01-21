#include <bits/stdc++.h>
using namespace std;


vector<vector<long long>> MatrixMulti(int n,vector<vector<long long>>& m1, vector<vector<long long>>& m2)
{
    vector<vector<long long>> result(n, vector<long long>(n));
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int p = 0; p < n; p++)
            {
                result[i][j] += m1[i][p] * m2[p][j];
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> matrix(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<vector<long long>> result(n, vector<long long>(n,0));
    long long count = 0;
    while (count < n)
    {
        result[count][count] = 1;
        count++;
    }

    while (m > 0)
    {
        if (m % 2 == 1)
        {
           result = MatrixMulti(n, result, matrix);
        }
        matrix = MatrixMulti(n, matrix, matrix);
        m /= 2;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}