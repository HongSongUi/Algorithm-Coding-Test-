#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int W, V;

    vector<pair<int, int>> arr(N);
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 0; i < N; i++)
    {
        cin >> W >> V;
        arr[i] = make_pair(W, V);
    }

    int cur_weight;
    int cur_value;
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < K + 1; j++)
        {
            cur_weight = arr[i - 1].first;
            cur_value = arr[i - 1].second;
            if (cur_weight <= j)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cur_weight] + cur_value);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K];
    return 0;
}