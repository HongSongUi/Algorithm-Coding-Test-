#include <bits/stdc++.h>
using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> arr(n+1);
	vector<bool> dp(n+1, false);

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = true;
	for (int i = 1; i < n; i++)
	{
		if (!dp[i]) continue;
		for (int j = i + 1; j <= n; j++)
		{
			int cost = (j - i) * (1 + abs(arr[i] - arr[j]));
			if (cost <= k)
			{
				dp[j] = true;
			}
		}
	}
	if (dp[n] == true)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	
	return 0;
}