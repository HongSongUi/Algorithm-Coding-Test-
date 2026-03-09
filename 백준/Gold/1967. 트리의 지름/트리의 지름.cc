#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n;

vector<vector<pair<int,int>>> graph;

void BFS(int p , int& far_node, int& far_dist)
{
	vector<bool> visited(n + 1);
	visited[p] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(p, 0));
	int d = 0;
	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_dist = q.front().second;
		if (d < cur_dist)
		{
			d = cur_dist;
			far_node = cur_node;
			far_dist = cur_dist;
		}
		q.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			int next_dist = cur_dist + graph[cur_node][i].second;
			if (!visited[next_node])
			{
				visited[next_node] = true;
				q.push(make_pair(next_node, next_dist));
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

	graph.resize(n + 1);
	int s, e, c;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> s >> e >> c;
		graph[s].emplace_back(make_pair(e, c));
		graph[e].emplace_back(make_pair(s, c));
	}
	int n1 = 0;
	int answer = 0;
	int tmp = 0;
	BFS(1, n1, answer);
	BFS(n1, tmp, answer);
	cout << answer;
	return 0;
}