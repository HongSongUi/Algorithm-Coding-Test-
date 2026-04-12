#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int>p;

vector<int> rankVec;

int Find(int x)
{
	if (p[x] == x) return x;
	
	return p[x] = Find(p[x]);
}

bool Union(int u, int v)
{
	int up = Find(u);
	int vp = Find(v);

	if (up == vp) return true;

	if (rankVec[up] < rankVec[vp])
	{
		p[up] = vp;
	}
	else if (rankVec[up] > rankVec[vp])
	{
		p[vp] = up;
	}
	else
	{
		p[up] = vp;
		rankVec[vp]++;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;
	p.resize(n + 1);
	rankVec.resize(n + 1);
	vector<tuple<int, int, int>> edges(m);
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	int u, v, cost;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cost;
		edges[i] = make_tuple(cost, u, v);
	}
	sort(edges.begin(), edges.end());
	int answer = 0;
	int cnt = 0;
	int max_cost = 0;
	for (int i = 0; i < m; i++)
	{
		u = get<1>(edges[i]);
		v = get<2>(edges[i]);
		cost = get<0>(edges[i]);
		if (Union(u, v)) continue;
		answer += cost;
		cnt++;
		max_cost = max(max_cost, cost);
		if (cnt == n - 1) break;
	}
	cout << answer - max_cost;
	return 0;
}