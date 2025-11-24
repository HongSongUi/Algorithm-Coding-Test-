#include <bits/stdc++.h>

using namespace std;
#define INF 1000000007

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n, vector<int>(m, 0));
	for (int i = 0; i < puddles.size(); i++)
	{
		int x = puddles[i][0];
		int y = puddles[i][1];
		dp[y - 1][x - 1] = -1;
	}
	for (int i = 0; i < m; i++)
	{
		if (dp[0][i] == -1) break;
		dp[0][i] = 1;
	}

	for (int i = 0; i < n; i++)
	{
		if (dp[i][0] == -1) break;
		dp[i][0] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (dp[i][j] == -1) continue;

			int t = dp[i - 1][j];
			int l = dp[i][j - 1];
			if (t == -1)
			{
				dp[i][j] = l % INF;
			}
			else if (l == -1)
			{
				dp[i][j] = t % INF;
			}
			else
			{
				dp[i][j] = (t + l) % INF;
			}

		}
	}

	answer = dp[n - 1][m - 1];
    return answer;
}