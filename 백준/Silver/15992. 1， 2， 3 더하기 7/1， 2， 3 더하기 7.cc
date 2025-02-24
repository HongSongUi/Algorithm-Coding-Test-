#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 0;
	cin >> T;
	vector<vector<long long>> dp(1001, vector<long long>(1001, 0));
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	for (int i = 3; i <= 1000; i++)
	{
		for (int j = 2; j <= 1000; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 2][j - 1] + dp[i - 3][j - 1]) % 1000000009;
		}
	}
	while (T--)
	{
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << '\n';
	}
	return 0;
}