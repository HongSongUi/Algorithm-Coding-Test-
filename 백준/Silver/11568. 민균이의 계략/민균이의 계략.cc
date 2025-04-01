#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int answer = *max_element(dp.begin(), dp.end());
    cout << answer;
    return 0;
}