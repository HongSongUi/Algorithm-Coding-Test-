#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	vector<pair<int, int>> arr;
	int dir = 0;
	int len = 0;
	for (int i = 0; i < 6; i++)
	{
		cin >> dir >> len;
		arr.emplace_back(make_pair(dir, len));
	}

	int max_width = 0, max_height = 0;
	int wIndex = 0, hIndex = 0;

	for (int i = 0; i < arr.size(); i++)
	{
		dir = arr[i].first;
		len = arr[i].second;
		if (dir<=2 && len > max_width)
		{
			max_width = len;
			wIndex = i;
		}
		if (dir >= 3 && len > max_height)
		{
			max_height = len;
			hIndex = i;
		}
	}
	int small_area = arr[(hIndex + 3) % 6].second * arr[(wIndex + 3) % 6].second;
	int answer = ((max_width * max_height) - small_area) * n;
	cout << answer;
	return 0;
}