#include <bits/stdc++.h>
using namespace std;

int answer;
int n;
int m;

vector<int> dx = { 0,0,-1,1 };
vector<int> dy = { -1,1,0,0 };

bool PointCheck(int x, int y)
{
	if ((x >= 0 && x < m) && (y >= 0 && y < n))
	{
		return true;
	}
	return false;
}

void DFS(int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& visit, int score, int depth)
{
	if (depth == 4)
	{
		answer = max(answer, score);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (PointCheck(next_x, next_y) && !visit[next_y][next_x])
		{
			visit[next_y][next_x] = true;
			DFS(next_x, next_y, arr, visit, score + arr[next_y][next_x], depth + 1);
			visit[next_y][next_x] = false;
		}
	}
}

void RemainCheck(int x, int y, vector<vector<int>>& arr)
{
	for (int i = 0; i < 4; i++)
	{
		int score = arr[y][x];
		for (int j = 0; j < 4; j++)
		{
			int next_x = x + dx[j];
			int next_y = y + dy[j];
			if (i != j && PointCheck(next_x,next_y))
			{
				score += arr[next_y][next_x];
			}
		}
		answer = max(answer, score);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	
	cin >> n >> m;
	answer = 0;
	vector<vector<int>> arr(n, vector<int>(m, 0));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			visit[i][j] = true;
			DFS(j, i, arr, visit, arr[i][j], 1);
			visit[i][j] = false;
			RemainCheck(j, i, arr);
		}
	}
	
	cout << answer;
}