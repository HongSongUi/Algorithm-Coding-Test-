#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<vector<long long>> dp(n + 1, vector<long long>(10));

	for (int i = 1; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = dp[i - 1][1] % 1000000000;
		for (int j = 1; j < 9; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
		dp[i][9] = dp[i - 1][8] % 1000000000;
	}
	long long answer = 0;
	for (int i = 0; i < 10; i++)
	{
		answer = (answer+ dp[n][i]) % 1000000000;
	}
	cout << answer;

	return 0;
}