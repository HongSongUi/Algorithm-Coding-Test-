#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<int> dp(n + 1, 0);
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		if (arr[i] < arr[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			dp[i] = dp[i - 1];
		}
	}
	int x = 0, y = 0;
	int q = 0;
	cin >> q;
	while (q--)
	{
		cin >> x >> y;
		cout << dp[y] - dp[x] << '\n';
	}
	return 0;
}