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
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> graph(n);
	for (int i = 0; i < n; i++)
	{
		cin >> graph[i].first >> graph[i].second;
	}
	sort(graph.begin(), graph.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << graph[i].first << ' ' << graph[i].second << '\n';
	}
	return 0;
}