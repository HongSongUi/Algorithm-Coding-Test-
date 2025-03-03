#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<pair<int,int>>> graph;
void BFS(int start)
{
	vector<bool> visited(n + 1, false);
	queue<pair<int, long long>> q;
	q.push(make_pair(start, 0));
	long long dist = 0;
	visited[start] = true;
	while (!q.empty())
	{
		int cur_node = q.front().first;
		long long cur_dist = q.front().second;
		q.pop();
		if (cur_dist > dist)
		{
			dist = cur_dist;
		}
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i].first;
			long long next_dist = graph[cur_node][i].second;
			
			if (visited[next_node] == false)
			{
				visited[next_node] = true;
				q.push(make_pair(next_node, cur_dist + next_dist));
			}
		}
	}
	cout <<dist;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	graph.resize(n+1);

	int from, to;
	long long cost;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> from >> to >> cost;
		graph[from].emplace_back(make_pair(to, cost));
		graph[to].emplace_back(make_pair(from, cost));
	}
	BFS(1);
	return 0;
}