#include <bits/stdc++.h>

using namespace std;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };

int nx = 0;
int ny = 0;

struct Point
{
	int x = 0;
	int y = 0;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool IsValid(int x, int y)
{
	return (x >= 0 && x < nx) && (y >= 0 && y < ny);
}

int BFS(int sx, int sy, vector<vector<int>>& graph, int gx, int gy)
{
	vector<vector<bool>> visited(graph.size(), vector<bool>(graph[0].size(), false));
	queue<pair<Point, int >>q;
	q.push(make_pair(Point(sx,sy),0));
	visited[sy][sx] = true;
	
	while (!q.empty())
	{
		int cur_x = q.front().first.x;
		int cur_y = q.front().first.y;
		int cur_depth = q.front().second;
		
		q.pop();

		if (cur_x == gx && cur_y == gy)
		{
			return cur_depth;
		}
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (IsValid(next_x, next_y) && !visited[next_y][next_x] && graph[next_y][next_x] != -1)
			{
				q.push(make_pair(Point(next_x, next_y), cur_depth + 1));
				visited[next_y][next_x] = true;
			}

		}

	}

	return -1;
}
int solution(vector<string> maps) {
    int answer = 0;
    ny = maps.size();
	nx = maps[0].size();
	vector<vector<int>> graph(maps.size(), vector<int>(maps[0].size(), 0));
	int sx, sy, lx, ly, ex, ey;

	for (int i = 0; i < maps.size(); i++)
	{
		string s = maps[i];
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'S')
			{
				sx = j;
				sy = i;
				graph[i][j] = 1;
			}
			else if(s[j] == 'L')
			{
				lx = j;
				ly = i;
				graph[i][j] = 1;
			}
			else if (s[j] == 'E')
			{
				ex = j;
				ey = i;
				graph[i][j] = 1;
			}
			else if (s[j] == 'X')
			{
				graph[i][j] = -1;
			}
		}
	}

	int ld = BFS(sx, sy, graph, lx, ly);
	if (ld == -1) return -1;

	int ed = BFS(lx, ly, graph, ex, ey);
	if (ed == -1) return -1;

	answer = ld + ed;
    return answer;
}