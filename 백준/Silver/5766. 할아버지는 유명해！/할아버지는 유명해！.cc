#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>a, pair<int, int>b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;

	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		map<int, int> tmp;
		int num = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> num;
				tmp[num]++;
			}
		}
		vector<pair<int, int>> arr(tmp.begin(), tmp.end());
		sort(arr.begin(), arr.end(), cmp);
		int sec_point = arr[1].second;
		for (int i = 1; i < arr.size(); i++)
		{
			if (arr[i].second == sec_point)
			{
				cout << arr[i].first << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}