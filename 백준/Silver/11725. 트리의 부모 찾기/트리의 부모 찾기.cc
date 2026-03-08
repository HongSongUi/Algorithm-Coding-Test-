#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n = 0;
vector<vector<int>> graph;
vector<int> p;

void BFS()
{
	vector<bool> visited(n + 1);
	visited[1] = true;
	queue<int>q;
	q.push(1);
	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i];
			if (visited[next_node] == false)
			{
				visited[next_node] = true;
				q.push(next_node);
				p[next_node] = cur_node;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	p.resize(n + 1);
	graph.resize(n+1);

	int s, e;
	for (int i = 0; i < n-1; i++)
	{
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}
	BFS();
	for (int i = 2; i <= n; i++)
	{
		cout << p[i] << '\n';
	}
	return 0;
}