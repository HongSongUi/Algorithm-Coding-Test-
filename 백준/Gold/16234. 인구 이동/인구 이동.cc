#include <bits/stdc++.h>

using namespace std;

int n = 0;
int l = 0, r = 0;
vector<vector<int>> vec;

vector<pair<int, int>> dir = { {-1,0},{0,-1},{1,0},{0,1} };

bool IsValid(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
bool Diff(int cx,int cy, int nx,int ny)
{
	int d = abs(vec[cy][cx] - vec[ny][nx]);
	return (d >= l && d <= r);
}
void BFS(int x, int y, vector<vector<bool>>& visited, vector<vector<int>>& tmp)
{
	int num = 0;
	visited[y][x] = true;
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	vector<pair<int, int>> s;

	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		s.emplace_back(make_pair(cur_x, cur_y));

		num += vec[cur_y][cur_x];
		q.pop();
		
		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dir[i].first;
			int ny = cur_y + dir[i].second;
			if (IsValid(nx, ny) && !visited[ny][nx] && Diff(cur_x,cur_y,nx,ny))
			{
				visited[ny][nx] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int val = num / s.size();
	for (int i = 0; i < s.size(); i++)
	{
		int x = s[i].first;
		int y = s[i].second;
		tmp[y][x] = val;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> l >> r;
	vec.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}
	int days = 0;
	while (true)
	{
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		vector<vector<int>> tmp(n, vector<int>(n));
		tmp = vec;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j])
				{
					BFS(j, i, visited, tmp);
				}
			}
		}
		if (tmp == vec) break;

		vec = tmp;
		days++;
	}
	cout << days;
	return 0;
}
