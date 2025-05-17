#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][0] = 1;  
    dp[1][1] = 1;  
    dp[1][2] = 1;  

    for (int i = 2; i <= n; ++i) 
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }

    int result = (dp[n][0] + dp[n][1] + dp[n][2]) % 9901;
    cout << result << '\n';
	return 0;
}