#include <bits/stdc++.h>
using namespace std;
bool Cmp(pair<int, int> a, pair<int, int>b)
{
	return a.second < b.second;
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<pair<int, int>>vec;
	for (int i = 0; i < routes.size(); i++)
	{
		int in = routes[i][0];
		int out = routes[i][1];
		vec.emplace_back(make_pair(in, out));
	}

	sort(vec.begin(), vec.end(),Cmp);

	int cnt = 1;
	int point = vec[0].second;
	for (int i = 1; i < vec.size(); i++)
	{
		if (point < vec[i].first)
		{
			cnt++;
			point = vec[i].second;
		}
	}
	answer = cnt;
    return answer;
}