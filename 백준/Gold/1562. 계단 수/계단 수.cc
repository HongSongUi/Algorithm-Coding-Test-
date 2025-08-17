#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int dp[101][10][1 << 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    for (int i = 1; i <= 9; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    for (int len = 1; len < n; len++) 
    {
        for (int last = 0; last <= 9; last++) 
        {
            for (int mask = 0; mask < (1 << 10); mask++) 
            {
                int cur = dp[len][last][mask];
                if (!cur) continue;

                if (last > 0) 
                {
                    int nm = mask | (1 << (last - 1));
                    dp[len + 1][last - 1][nm] = (dp[len + 1][last - 1][nm] + cur) % 1000000000;
                }
                if (last < 9)
                {
                    int nm = mask | (1 << (last + 1));
                    dp[len + 1][last + 1][nm] = (dp[len + 1][last + 1][nm] + cur) % 1000000000;
                }
            }
        }
    }

    int full = (1 << 10) - 1;
    long long ans = 0;
    for (int last = 0; last <= 9; last++) 
    {
        ans = (ans + dp[n][last][full]) % 1000000000;
    }

    cout << ans << "\n";
    return 0;
}