#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size(), 0));
	
	dp[0][0] = triangle[0][0];
	dp[1][0] = dp[0][0] + triangle[1][0];
	dp[1][1] = dp[0][0] + triangle[1][1];

	int answer = 0;

	for (int i = 2; i < triangle.size(); i++)
	{
		for (int j = 0; j < triangle[i].size(); j++)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i - 1][j] + triangle[i][j];
			}
			else if (j == triangle[i].size() - 1)
			{
				dp[i][j] = dp[i - 1][j-1] + triangle[i][j];
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
		}
	}
	answer = *max_element(dp[triangle.size() - 1].begin(), dp[triangle.size() - 1].end());
    return answer;
}