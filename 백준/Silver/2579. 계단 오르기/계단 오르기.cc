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
	vector<int>vec(n+1,0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i+1];
	}
	vector<int>dp(n + 1);
	dp[0] = 0;
	dp[1] = vec[1];
	dp[2] = vec[2] + dp[1];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = vec[i] + max(dp[i - 2] , dp[i - 3] + vec[i - 1]);
	}
	cout << dp[n];
	return 0;
}
