#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n, m;

vector<vector<int>> graph;

int answer = 0;
void DFS(int cur)
{
	if (cur == m) return;

	int cnt = 0;

	for (int i = 0; i < graph[cur].size(); i++)
	{
		int next_node = graph[cur][i];
		if (next_node == m) continue;
		cnt++;
		DFS(next_node);
	}
	if (cnt == 0)
	{
		answer++;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int p = 0;

	graph.resize(n);
	int r = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> p;
		if (p == -1)
		{
			r = i;
			continue;
		}
		graph[p].emplace_back(i);


	}
	
	cin >> m;
	DFS(r);
	cout << answer;
	return 0;
}