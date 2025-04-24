#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;

    int count = 1;
    while (true)
    {
        cin >> num;
        if (num == 0)
        {
            break;
        }
        vector<vector<int>> cycle(num, vector<int>(3));
        vector<vector<int>> dp(num, vector<int>(3));
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cin >> cycle[i][j];
            }
        }
        dp[0][0] = INT_MAX;
        dp[0][1] = cycle[0][1];
        dp[0][2] = dp[0][1] + cycle[0][2];
        for (int i = 1; i < num; i++)
        {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + cycle[i][0];
            dp[i][1] = min(min(dp[i - 1][0], dp[i - 1][1]), min(dp[i - 1][2], dp[i][0])) + cycle[i][1];
            dp[i][2] = min(min(dp[i - 1][1], dp[i - 1][2]), dp[i][1]) + cycle[i][2];
        }
        cout << count << ". " << dp[num - 1][1] << '\n';
        count++;
    }
    return 0;
}