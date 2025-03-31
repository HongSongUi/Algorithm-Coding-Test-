#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, k = 0;

    
    cin >> n >> k;
    vector<int> arr(n);
    vector<vector<int>> dp(n, vector<int>(k + 1));
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];

    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            if (arr[i] % 2 == 0)
            {
                dp[i][j] = (i > 0) ? dp[i - 1][j] + 1 : 1;
            }
            else
            {
                if (j > 0)
                {
                    dp[i][j] = (i > 0) ? dp[i - 1][j - 1] : 0;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
            answer = max(answer, dp[i][j]);
        }
    }
    cout << answer;
    return 0;
}