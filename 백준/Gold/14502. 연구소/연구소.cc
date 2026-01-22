#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int n = 0;
int m = 0;
vector<vector<int>> graph;
vector<pair<int, int>> sPoints;

vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
int mSize = 0;

bool IsValid(int x, int y)
{
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}

void BFS()
{
	vector<vector<int>> tmp = graph;
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	queue<pair<int, int>> q;
	for (int i = 0; i < sPoints.size(); i++)
	{
		q.push(make_pair(sPoints[i].first, sPoints[i].second));
		visited[sPoints[i].second][sPoints[i].first] = true;
	}
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;

		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (IsValid(nx, ny) && !visited[ny][nx] && tmp[ny][nx] != 1 && tmp[ny][nx] != 2)
			{
				q.push(make_pair(nx, ny));
				visited[ny][nx] = true;
				tmp[ny][nx] = 2;
			}
		}
	}
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == 0) s++;
		}
	}
	mSize = max(mSize, s);
	return;
}

void MakeWall(int cnt, int sx)
{
	if (cnt == 3)
	{
		BFS();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = sx; j < m; j++)
		{
			if (graph[i][j] == 0)
			{
				graph[i][j] = 1;
				MakeWall(cnt + 1, j);
				graph[i][j] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;

	graph.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] == 2)
			{
				sPoints.emplace_back(make_pair(j, i));
			}
		}
	}
	MakeWall(0,0);
	cout << mSize;
	return 0;
}
