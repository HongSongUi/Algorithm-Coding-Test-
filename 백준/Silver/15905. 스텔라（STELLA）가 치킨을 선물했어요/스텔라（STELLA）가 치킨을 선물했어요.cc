#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr.begin(), arr.end(), cmp);
	int answer = 0;
	int target = arr[4].first;
	for(int i = 5; i<arr.size(); i++)
	{
		if (arr[i].first == target)
		{
			answer++;
		}
		else
		{
			break;
		}
	}
	cout << answer;
	return 0;
}