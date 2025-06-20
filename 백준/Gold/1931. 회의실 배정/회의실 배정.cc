#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> tmp(n);
	int s = 0;
	int e = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		tmp[i] = make_pair(s, e);
	}
	sort(tmp.begin(), tmp.end(), cmp);
	int answer = 0;
	e = 0;
	for (int i = 0; i < n; i++)
	{
		if (tmp[i].first >= e)
		{
			e = tmp[i].second;
			answer++;
		}
	}
	cout << answer;
	return 0;
}