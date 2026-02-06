#include <bits/stdc++.h>

using namespace std;

struct Node
{
	pair<int, int> dir;
	bool snake;
	bool apple;
	Node()
	{
		dir = { 1,0 };
		snake = false;
		apple = false;
	}
	Node(bool s, bool a)
	{
		snake = s;
		apple = a;
	}
};

int n = 0;
pair<int, int> head_point = { 0,0 };
pair<int, int> tail_point = { 0,0 };
vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0}, {0,-1} }; // x,y

bool IsValid(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k = 0;
	int l = 0;
	cin >> n >> k;
	vector<vector<Node>> graph(n, vector<Node>(n));
	int n1, n2;
	for (int i = 0; i < k; i++)
	{
		cin >> n1 >> n2;
		graph[n1 - 1][n2 - 1].apple = true;
	}
	cin >> l;
	queue<pair<int, int>> orders;
	int t;
	string tmp;
	int d;
	for (int i = 0; i < l; i++)
	{
		cin >> t >> tmp;
		d = (tmp == "D") ? 1 : -1;
		orders.push(make_pair(t, d));
	}
	int cur_time = 0;
	graph[0][0].snake = true;
	int idx = 0;

	while (true)
	{
		cur_time++;
		pair<int, int> cur_dir = dir[idx];
		int px = head_point.first;
		int py = head_point.second;

		int nx = px + cur_dir.first;
		int ny = py + cur_dir.second;

		graph[py][px].dir = cur_dir;
		if (!IsValid(nx, ny)) break;
		if (graph[ny][nx].snake) break;
		head_point = make_pair(nx, ny );
		graph[ny][nx].snake = true;


		if (graph[ny][nx].apple)
		{
			graph[ny][nx].apple = false;
		}
		else if (!graph[ny][nx].apple)
		{
			pair<int, int> t_dir = graph[tail_point.second][tail_point.first].dir;
			graph[tail_point.second][tail_point.first].snake = false;
			tail_point.first += t_dir.first;
			tail_point.second += t_dir.second;
		}
		
		if (!orders.empty() && cur_time == orders.front().first)
		{
			int next_dir = orders.front().second;
			orders.pop();
			idx = (idx + next_dir + dir.size()) % dir.size();

		}

	}
	cout << cur_time;
	return 0;
}
