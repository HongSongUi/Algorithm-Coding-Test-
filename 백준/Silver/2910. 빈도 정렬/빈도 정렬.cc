#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

map<int, int> idx;
map<int, int> cnt;

bool cmp(int a, int b)
{
	if (cnt[a] == cnt[b])
	{
		return idx[a] < idx[b];
	}
	return cnt[a] > cnt[b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int c = 0;
	cin >> n >> c;
	vector<int> vec;
	int number = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		if (cnt[number] == 0)
		{
			vec.emplace_back(number);
			idx[number] = i;
		}
		cnt[number]++;
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++)
	{
		int freq = cnt[vec[i]];
		while (freq--)
		{
			cout << vec[i] << ' ';
		}
	}
	return 0;
}
