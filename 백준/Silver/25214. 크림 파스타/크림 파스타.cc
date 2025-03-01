#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	cin >> n;
	vector<int> dp(n);
	int num = 0;
	cin >> num;
	dp[0] = 0;
	int minVal = num;
	for (int i = 1; i < n; i++)
	{
		cin >> num;
		dp[i] = max(dp[i - 1], num - minVal);
		if (minVal > num)
		{
			minVal = num;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << dp[i] << " ";
	}
	return 0;
}