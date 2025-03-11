#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	vector<int> dp(100001, 0);
	dp[1] = -1;
	dp[2] = 1;
	dp[3] = -1;
	for (int i = 4; i <= n; i++)
	{
		if (i % 5 == 0)
		{
			dp[i] = i / 5;
		}
		else
		{
			dp[i] = dp[i - 2] + 1;
		}
	}
	cout << dp[n];
	return 0;
}