#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	
	vector<int> dp(n+1);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		if (i >= 2)
		{
			dp[i] = min(dp[i], dp[i - 2]);
		}
		if (i >= 5)
		{
			dp[i] = min(dp[i], dp[i - 5]);
		}
		if (i >= 7)
		{
			dp[i] = min(dp[i], dp[i - 7]);
		}
		dp[i]++;
	}
	cout << dp[n];

	return 0;
}