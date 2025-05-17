#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0, k = 0;
	cin >> n >> k;
	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
		}
	}
	cout << dp[n][k];
	return 0;
}