#include <bits/stdc++.h>
using namespace std;

long long n;

vector<vector<long long>> Multyply(vector<vector<long long>>& m1, vector<vector<long long>>& m2)
{
    vector<vector<long long>> result(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            result[j][i] = (m1[j][0] * m2[0][i] + m1[j][1] * m2[1][i]) % 1000000007;
        }
    }
    return result;
}

vector<vector<long long>> Power(vector<vector<long long>>& m)
{
    vector<vector<long long>> result = { {1,0},{0,1} };
    long long count = n - 1;
    while (count > 0)
    {
        if (count % 2 == 1)
        {
            result = Multyply(result, m);
        }
        m = Multyply(m, m);
        count /= 2;
    }
    return result;
}

long long fibonacci()
{
    vector<vector<long long>> M = { {1,1},{1,0} };
    vector<vector<long long>> result = Power(M);
    
    return result[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;

    if (n == 0)
    {
        cout << 0;
    }
    else if (n == 1)
    {
        cout << 1;
    }
    else
    {
        cout << fibonacci();
    }
    return 0;
}