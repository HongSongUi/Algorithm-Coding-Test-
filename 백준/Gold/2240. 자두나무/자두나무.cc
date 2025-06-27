#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t = 0, w = 0;
	cin >> t >> w;
	
	vector<int> arr(t+1);
	for (int i = 1; i <= t; i++)

	{		cin >> arr[i];
	}
	vector<vector<vector<int>>> dp(t+1, vector<vector<int>>(w+1, vector<int>(3)));
	
	dp[1][0][1] = (arr[1] == 1) ? 1 : 0;
	dp[1][1][2] = (arr[1] == 2) ? 1 : 0;
	for (int i = 2; i <= t; i++)
	{
		for (int j = 0; j <= w; j++)
		{
			if (j == 0)
			{
				dp[i][0][1] = dp[i - 1][0][1] + (arr[i] == 1);
				dp[i][0][2] = dp[i - 1][0][2] + (arr[i] == 2);
			} 
			else
			{
				dp[i][j][1] = max(dp[i-1][j][1] , dp[i-1][j-1][2]) + ((arr[i] == 1) ? 1 : 0);
				dp[i][j][2] = max(dp[i-1][j][2], dp[i-1][j-1][1]) + ((arr[i] == 2) ? 1 : 0);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i <= w; i++)
	{
		answer = max(answer, max(dp[t][i][1], dp[t][i][2]));
	}
	cout << answer;
	return 0;
}