#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> temp;
int numCount = 0;
void Find(int num)
{
	if (num == n)
	{
		numCount++;
		if (numCount == k)
		{
			for (int i = 0; i < temp.size(); i++)
			{
				cout << temp[i];
				if (i != temp.size() - 1) cout << "+";
			}
		}
		return;
	}
	if (num > n)
	{
		return;
	}
	for (int i = 1; i <= 3; i++)
	{	
		temp.emplace_back(i);
		Find(num + i);
		temp.pop_back();
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	vector<int> dp(12,0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 12; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	if (k > dp[n])
	{
		cout << -1;
	}
	else
	{
		Find(0);
	}
	return 0;
}