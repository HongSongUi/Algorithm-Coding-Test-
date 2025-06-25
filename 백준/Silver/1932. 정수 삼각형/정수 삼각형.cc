#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> num;
			arr[i].emplace_back(num);
		}
	}
	vector<vector<int>> dp(n,vector<int>(n));
	dp[0][0] = arr[0][0];
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j <= i+1; j++)
		{
			if (j == 0)
			{
				dp[i + 1][j] = arr[i+1][j] + dp[i][j];
				continue;
			}
			else if (j == i + 1)
			{
				dp[i + 1][j] = arr[i + 1][j] + dp[i][j-1];
				continue;
			}
			dp[i + 1][j] =arr [i+1][j] + max(dp[i][j - 1], dp[i][j]);
		}
	}
	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}