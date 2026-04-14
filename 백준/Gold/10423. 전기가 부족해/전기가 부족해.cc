#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> p;

int FindParent(int x)
{
	if (p[x] == x) return x;
	return p[x] = FindParent(p[x]);
}
bool Union(int u, int v)
{
	int u_parent = FindParent(u);
	int v_parent = FindParent(v);

	if (u_parent == v_parent) return true;

	p[u_parent] = v_parent;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	p.resize(n+1);
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
	int city = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> city;
		p[city] = 0;
	}
	vector<tuple<int, int, int>> edges(m);
	int u, v, w;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		edges[i] = make_tuple(w, u, v);
	}
	sort(edges.begin(), edges.end());

	int answer = 0;
	int cnt = 0;

	for (int i = 0; i < m; i++)
	{
		w = get<0>(edges[i]);
		u = get<1>(edges[i]);
		v = get<2>(edges[i]);

		if (Union(u, v)) continue;

		answer += w;
		cnt++;
		if (cnt == n - 1) break;
	}
	cout << answer;
	return 0;
}