#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<vector<int>> vec(n, vector<int>(3));
	vector<vector<int>> dp(n, vector<int>(3));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> vec[i][j];
		}
	}
	dp[0][0] = vec[0][0];
	dp[0][1] = vec[0][1];
	dp[0][2] = vec[0][2];

	for (int i = 1; i < n; i++)
	{
		dp[i][0] = vec[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = vec[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = vec[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}

	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}
