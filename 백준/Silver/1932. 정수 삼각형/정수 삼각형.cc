#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(0, 0));
	vector<vector<int>> dp(n, vector<int>(n, -1));
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> num;
			arr[i].emplace_back(num);
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 0; i < arr.size()-1; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			int cur_num = dp[i][j];
			int next_left = cur_num + arr[i + 1][j];
			int next_right = cur_num + arr[i + 1][j + 1];
			if (dp[i + 1][j] != -1)
			{
				next_left = max(next_left, dp[i + 1][j]);
			}
			if (dp[i + 1][j + 1] != -1)
			{
				next_right = max(next_right, dp[i + 1][j + 1]);
			}
			dp[i + 1][j] = next_left;
			dp[i + 1][j + 1] = next_right;
		}
	}
	int answer = *max_element(dp[n - 1].begin(), dp[n - 1].end());
	cout << answer;
}