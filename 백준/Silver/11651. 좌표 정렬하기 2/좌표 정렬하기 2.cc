#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int>b)
{
	if (b.second == a.second) return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<pair<int, int>>vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << vec[i].first << ' ' << vec[i].second << '\n';
	}
	return 0;
}
