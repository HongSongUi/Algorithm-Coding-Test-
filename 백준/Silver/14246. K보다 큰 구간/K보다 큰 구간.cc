#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> arr(n+1,0);
	vector<long long> dp(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i] + dp[i - 1];
	}

	int k = 0;
	cin >> k;
	long long answer = 0;
	for (int i = 1; i <= n; i++)
	{
		long long num = dp[i - 1];
		auto it = upper_bound(dp.begin(), dp.end(), num + k);
		if (it != dp.end())
		{
			answer += dp.end() - it;
		}
	}
	cout << answer;
	return 0;
}