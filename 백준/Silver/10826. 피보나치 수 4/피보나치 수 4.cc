#include <bits/stdc++.h>
using namespace std;

string AddNum(string a, string b)
{
	string result = "";
	int tmp = 0;
	if (a.size() < b.size()) swap(a, b);
	while (b.size() < a.size()) b = "0" + b;
	
	for (int i = a.size() - 1; i >= 0; i--)
	{
		int sum = (a[i] - '0') + (b[i] - '0') + tmp;
		result += (sum % 10) + '0';
		tmp = sum / 10;
	}
	if (tmp)
	{
		result += tmp + '0';
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	int n = 0;
	cin >> n;
	vector<string>dp(n + 2);
	dp[0] = "0";
	dp[1] = "1";
	for (int i = 2; i <= n; i++)
	{
		dp[i] = AddNum(dp[i - 1], dp[i - 2]);
	}
	cout << dp[n];
	return 0;
}
