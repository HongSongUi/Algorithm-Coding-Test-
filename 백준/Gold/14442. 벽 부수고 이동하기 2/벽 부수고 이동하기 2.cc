#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<vector<int>> graph;

vector<int> dx = { -1, 0,1, 0 };
vector<int> dy = { 0,-1,0,1 };

struct Point
{
	int x;
	int y;
	int b;
	Point(int x, int y, int b)
	{
		this->x = x;
		this->y = y;
		this->b = b;
	}
};
bool IsValid(int x, int y)
{
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}

int BFS()
{
	int dist = -1;

	vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(m, vector<bool>(k+1, false)));
	queue<pair<Point, int>> q;
	visited[0][0][0] = true;
	q.push(make_pair(Point(0, 0, 0), 1));
	while (!q.empty())
	{
		int cur_x = q.front().first.x;
		int cur_y = q.front().first.y;
		int cur_cnt = q.front().first.b;
		int cur_depth = q.front().second;
		q.pop();

		if (cur_x == (m - 1) && cur_y == (n - 1))
		{
			dist = cur_depth;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (IsValid(nx, ny))
			{
				if (graph[ny][nx] == 1 && cur_cnt < k && !visited[ny][nx][cur_cnt+1])
				{
					q.push(make_pair(Point(nx, ny, cur_cnt + 1), cur_depth + 1));
					visited[ny][nx][cur_cnt + 1] = true;
				}
				else if (graph[ny][nx] == 0 && !visited[ny][nx][cur_cnt])
				{
					q.push(make_pair(Point(nx, ny, cur_cnt), cur_depth + 1));
					visited[ny][nx][cur_cnt] = true;
				}
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

	cin >> n >> m >> k;
	string str = "";
	graph.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			graph[i][j] = str[j] - '0';
		}
	}
	int answer = BFS();
	cout << answer;
	return 0;
}
