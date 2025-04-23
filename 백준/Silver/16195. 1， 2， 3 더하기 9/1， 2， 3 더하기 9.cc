#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    int n = 0, m = 0;
    cin >> t;
    vector<vector<long long>> dp(1001, vector<long long>(1001, 0));
    dp[1][1] = 1;
    dp[2][1] = 1;
    dp[2][2] = 2;
    dp[3][1] = 1;
    dp[3][2] = 3;
    dp[3][3] = 4;
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 2; j < 1001; j++)
        {
            if (j > i)
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    for (int i = 4; i < 1001; i++)
    {
        for (int j = 2; j < 1001; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009;
        }
    }
    while (t--)
    {
        cin >> n >> m;
        cout << dp[n][m] << '\n';
    }
    return 0;
}