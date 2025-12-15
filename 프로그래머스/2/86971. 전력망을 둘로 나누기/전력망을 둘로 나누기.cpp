#include <bits/stdc++.h>
using namespace std;
int BFS(vector<vector<int>>& graph, int n, int p)
{
	vector<bool> vistied(n+1, false);

	queue<int> q;
	q.push(p);
	vistied[p] = true;
	int ret = 1;
	while (!q.empty())
	{
		int cur_point = q.front();


		q.pop();
		for (int i = 0; i < graph[cur_point].size(); i++)
		{
			int next_point = graph[cur_point][i];
			if (vistied[next_point] == false)
			{
				q.push(next_point);
				vistied[next_point] = true;
				ret++;
			}
		}
	}
	return ret;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    int from, to;
	int min_dist = INT_MAX;
	for (int i = 0; i < wires.size(); i++)
	{
		vector<vector<int>> graph(n + 1);
		int p1 = wires[i][0];
		int p2 = wires[i][1];
		for (int j = 0; j < wires.size(); j++)
		{
			if (i == j) continue;

			from = wires[j][0];
			to = wires[j][1];
			graph[from].emplace_back(to);
			graph[to].emplace_back(from);
		}
		int c1 = BFS(graph, n, p1);
		int c2 = BFS(graph, n, p2);
		
		min_dist = min(abs(c1 - c2), min_dist);

	}
	answer = min_dist;
    return answer;
}