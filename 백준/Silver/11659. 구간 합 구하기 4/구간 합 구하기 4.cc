#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0, t = 0;
	cin >> n >> t;

	vector<int> vec(n);
	vector<int> dp(n+1,0);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
		dp[i + 1] = dp[i] + vec[i];
	}
	while (t--)
	{
		int s = 0;
		int e = 0;
		cin >> s >> e;
		cout << dp[e] - dp[s - 1] << '\n';
	}
	return 0;
}
