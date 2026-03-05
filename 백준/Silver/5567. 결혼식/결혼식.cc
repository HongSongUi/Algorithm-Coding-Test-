#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n, m;
vector<vector<int>> graph;
vector<bool> visited;

int bfs()
{
	visited[1] = true;
	queue<pair<int, int>> q;
	int ret = 0;
	q.push(make_pair(1, 0));

	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_d = q.front().second;
		if (cur_d >= 1 && cur_d <= 2)
		{
			ret++;
		}
		q.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i];
			if (visited[next_node] == false)
			{
				visited[next_node] = true;
				q.push(make_pair(next_node, cur_d + 1));
			
			}
		}
	}
	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	graph.resize(n + 1);
	visited.resize(n + 1);
	int s, e;

	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}

	int answer = bfs();
	
	cout << answer;

	return 0;
}