#include <bits/stdc++.h>
using namespace std;

#define INF 1000000000
vector<int> dp;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n' << 0;
        return 0;
    }
    dp.resize(abs(n) + 1);
    dp[1] = 1;
    dp[0] = 0;
    if (n < 0)
    {
        n *= -1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (abs(dp[i - 1]) + abs(dp[i - 2])) % INF;
            if (i % 2 == 0)
            {
                dp[i] *= -1;
            }
        }
    }
    else
    {
        for (int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i - 1] + dp[i - 2]) % INF;
        }
    }
    if (dp[n] < 0)
    {
        cout << -1 << '\n';
    }
    else if(dp[n]>0)
    {
        cout << 1 << '\n';
    }
    cout << abs(dp[n]) % INF;
    return 0;
}