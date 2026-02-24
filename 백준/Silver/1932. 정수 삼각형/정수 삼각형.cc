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
	vector<vector<int>>  vec(n,vector<int>(n));
	vector<vector<int>> dp(n, vector<int>(n));
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> vec[i][j];		
		}
	}
	dp[0][0] = vec[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][j];
			}
			else if (j == i)
			{
				dp[i][j] = vec[i][j] + dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = vec[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}
