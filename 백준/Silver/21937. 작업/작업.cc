#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<vector<int>> graph;
int k = 0;
int answer = -1;

void DFS(int node)
{
	visited[node] = true;
	answer++;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int nextNode = graph[node][i];
		if(visited[nextNode] == false)
		{
			DFS(nextNode);
		}
	}
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	graph.resize(n + 1);
	visited.resize(n + 1, false);
	int from, to;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		graph[to].emplace_back(from);
	}
	cin >> k;

	DFS(k);

	cout << answer;
	return 0;
}