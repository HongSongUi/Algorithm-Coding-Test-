#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n, m;

vector<vector<pair<int,int>>> graph;

int BFS(int s, int e)
{
	vector<bool> visited(n + 1, false);
	queue<pair<int, int>> q;
	int dist = 0;
	q.push(make_pair(s, 0));

	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_dist = q.front().second;
		if (cur_node == e)
		{
			return cur_dist;
		}
		q.pop();
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			if (!visited[next_node])
			{
				visited[next_node] = true;
				q.push(make_pair(next_node, cur_dist + graph[cur_node][i].second));
			}
		}
	}

	return dist;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	

	int s, e, c;
	cin >> n >> m;
	graph.resize(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		cin >> s >> e >> c;
		graph[s].emplace_back(make_pair(e, c));
		graph[e].emplace_back(make_pair(s, c));
	}
	while (m--)
	{
		cin >> s >> e;
		cout << BFS(s, e) << '\n';
	}
	return 0;
}