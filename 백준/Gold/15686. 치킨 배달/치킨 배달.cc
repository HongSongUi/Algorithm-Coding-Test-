#include <bits/stdc++.h>

using namespace std;

int n;
int m;
vector<pair<int, int>> chickens;
vector<pair<int, int>> houses;
vector<pair<int, int>> choose;
vector<bool> visited;
int min_dist = INT_MAX;

void Distance()
{
	int dist = 0;
	for (int i = 0; i < houses.size(); i++)
	{
		int hx = houses[i].first;
		int hy = houses[i].second;
		int hd = INT_MAX;
		for (int j = 0; j < choose.size(); j++)
		{
			int cx = choose[j].first;
			int cy = choose[j].second;
			
			int tmp = abs(hx - cx) + abs(hy - cy);
			hd = min(hd, tmp);
		}
		dist += hd;
	}
	min_dist = min(dist, min_dist);
}

void BackTracking(int cnt, int idx)
{
	if (cnt == m)
	{
		Distance();
		return;
	}

	for (int i = idx; i < chickens.size(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			choose.emplace_back(chickens[i]);
			BackTracking(cnt + 1, i + 1);
			choose.pop_back();
			visited[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp == 2)
			{
				chickens.emplace_back(make_pair(j, i));
			}
			else if (tmp == 1)
			{
				houses.emplace_back(make_pair(j, i));
			}
		}
	}

	visited.resize(chickens.size() , false);
	BackTracking(0, 0);
	cout << min_dist;
	return 0;
}
