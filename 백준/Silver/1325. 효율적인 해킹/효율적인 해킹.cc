#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n , m;
vector<vector<int>> graph;
vector<int> vec;
int max_d = 0;
void BFS(int p)
{
	vector<bool> visited(n + 1);
	visited[p] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(p, 0));

	int d = 0;
	while (!q.empty())
	{
		int curPoint = q.front().first;
		int curDepth = q.front().second;
		q.pop();
		for (int i = 0; i < graph[curPoint].size(); i++)
		{
			int nextPoint = graph[curPoint][i];
			if (!visited[nextPoint])
			{
				visited[nextPoint] = true;
				q.push(make_pair(nextPoint, curDepth + 1));
				d++;
			}
		}
	}
	max_d = max(max_d, d);
	vec[p] = d;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	graph.resize(n + 1);
	vec.resize(n + 1);
	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		graph[e].emplace_back(s);
	}
	for (int i = 1; i <= n; i++)
	{
		BFS(i);
	}
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i] == max_d) cout << i << ' ';
	}
	return 0;
}