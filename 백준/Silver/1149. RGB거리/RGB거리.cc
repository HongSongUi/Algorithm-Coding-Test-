#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(3,0));
	vector<vector<int>> dp(n, vector<int>(3, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
	int idx = 0;
	int answer = 0;
	for (int i = 0; i < 3; i++)
	{
		dp[0][i] = arr[0][i];
	}
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = arr[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = arr[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = arr[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
	}
	cout << *min_element(dp[n - 1].begin(), dp[n - 1].end());
	return 0;
}