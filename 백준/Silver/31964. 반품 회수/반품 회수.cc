#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> house(n);
	for (int i = 0; i < n; i++)
	{
		cin >> house[i].first;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> house[i].second;
	}
	long long total_time = house[n - 1].first;
	if (total_time < house[n-1].second)
	{
		total_time = total_time + (house[n - 1].second - total_time);
	}
	long long cur_pos = house[n-1].first;
	for (int i = n - 2; i >= 0; i--)
	{
		total_time = total_time + (cur_pos - house[i].first);
		if (total_time < house[i].second)
		{
			total_time = house[i].second;
		}
		cur_pos = house[i].first;
	}
	total_time = total_time + cur_pos;
	cout << total_time;
	return 0;
}