#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string temp1 = "";
    string temp2 = "";
    cin >> temp1 >> temp2;
    int len1 = temp1.length();
    int len2 = temp2.length();
    vector<vector<int>> dp(len2 + 1, vector<int>(len1 + 1, 0));
    int answer = 0;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (temp2[i] != temp1[j])
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
            else if (temp2[i] == temp1[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }

        }
    }
    answer = dp[len2][len1];
    cout << answer;
    return 0;
}