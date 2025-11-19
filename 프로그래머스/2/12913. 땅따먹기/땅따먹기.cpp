#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

	int n = land.size();
	int m = land[0].size();
	vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < m; i++)
	{
		dp[0][i] = land[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int p = 0; p < m; p++)
			{
				if (j != p)
				{
					dp[i][j] = max(dp[i][j], dp[i-1][p] + land[i][j]);
				}
			}
		}
	}

	answer = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return answer;
}