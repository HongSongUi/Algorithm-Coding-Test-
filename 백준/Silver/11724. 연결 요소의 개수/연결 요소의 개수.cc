#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

void BFS(int p)
{
	visited[p] = true;
	queue<int> q;
	q.push(p);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next_p = graph[cur][i];
			if (!visited[next_p])
			{
				visited[next_p] = true;
				q.push(next_p);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	graph.resize(n+1);

	int s, e;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}
	visited.resize(n+1, false);
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			answer++;
			BFS(i);
		}
	}
	cout << answer;
	return 0;
}