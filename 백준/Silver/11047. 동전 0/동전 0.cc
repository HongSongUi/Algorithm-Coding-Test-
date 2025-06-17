#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int answer = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int cur_coin = arr[i];
		if (k < cur_coin) continue;
		while (k>=cur_coin)
		{
			k -= cur_coin;
			answer++;
		}
	}
	cout << answer;
	return 0;
}