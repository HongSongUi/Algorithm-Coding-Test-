#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n;
vector<vector<int>> graph;

vector<int> vec;
int min_depth = INT_MAX;
void bfs(int p)
{
	vector<bool> visited(n + 1, false);
	visited[p] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(p, 0));
	int d = 0;
	while (!q.empty())
	{
		int cur_node = q.front().first;
		int cur_depth = q.front().second;
		d = max(cur_depth, d);

		q.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int next_node = graph[cur_node][i];
			if (visited[next_node] == false)
			{
				visited[next_node] = true;
				q.push(make_pair(next_node, cur_depth + 1));
			}
		}
	}
	min_depth = min(d, min_depth);
	vec[p] = d;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	graph.resize(n + 1);
	vec.resize(n + 1);
	int s, e;

	while (true)
	{
		cin >> s >> e;
		if (s == -1 && e == -1)
		{
			break;
		}
		graph[s].emplace_back(e);
		graph[e].emplace_back(s);
	}
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	
	vector<int> tmp;
	for (int i = 1; i <= n; i++)
	{
		if (vec[i] == min_depth) tmp.emplace_back(i);
	}
	cout << min_depth << ' ' << tmp.size() << '\n';
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << tmp[i] << ' ';
	}
	return 0;
}