#include <bits/stdc++.h>
using namespace std;

bool Compare(pair<int, int >& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	int start = 0;
	int end = 0;
	vector<pair<int, int>> buff(N);
	for (int i = 0; i < N; i++)
	{
		cin >> start >> end;
		buff[i] = make_pair(start, end);
	}
	sort(buff.begin(), buff.end(), Compare);
	int count = 1;
	end = buff[0].second;
	for (int i = 1; i < buff.size(); i++)
	{
		if (buff[i].first >= end)
		{
			end = buff[i].second;
			count++;
		}
	}
	cout << count;
}