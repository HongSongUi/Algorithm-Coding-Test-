#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<double> arr(n+1);
	vector<double> dp(n+1);
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	double answer = -1;
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(arr[i], dp[i - 1] * arr[i]);
		answer = max(answer, dp[i]);
	}
	cout << fixed;
	cout.precision(3);
	cout << answer << '\n';
	return 0;
}