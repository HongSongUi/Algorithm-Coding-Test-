#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0, k = 0;
vector<vector<int>> graph;

int min_dist = INT_MAX;
int answer = -1;
bool find = false;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };

struct Point
{
	int x, y, depth, count;
};

bool IsValid(int x, int y)
{
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}
int FindDist()
{
	vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
	queue<Point> q;
	q.push({ 0, 0, 1, 0 });
	visited[0][0][0] = true;
	while (!q.empty())
	{
		int cur_x = q.front().x;
		int cur_y = q.front().y;
		int cur_depth = q.front().depth;
		int cur_count = q.front().count;
		q.pop();
		if (cur_x == m - 1 && cur_y == n - 1)
		{
			return cur_depth;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (IsValid(next_x, next_y))
			{
				if (graph[next_y][next_x] == 0 && !visited[next_y][next_x][cur_count])
				{
					visited[next_y][next_x][cur_count] = true;
					q.push({ next_x,next_y,cur_depth + 1,cur_count });
				}
				else if (graph[next_y][next_x] == 1 && cur_count +1 <= k && !visited[next_y][next_x][cur_count + 1])
				{
					visited[next_y][next_x][cur_count+1] = true;
					q.push({ next_x,next_y,cur_depth + 1,cur_count+1 });
				}
			}
		}
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	graph.resize(n, vector<int>(m));
	
	string s = "";
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = s[j] - '0';
		}
	}	
	cout << FindDist();
	return 0;
}