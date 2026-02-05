#include <bits/stdc++.h>

using namespace std;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
vector<vector<int>> vec;
int r, c;
int up_x, up_y;
int down_x, down_y;

bool IsValid(int x, int y)
{
	return (x >= 0 && x < c) && (y >= 0 && y < r);
}

void SpreadDust()
{
	vector<vector<int>> tmp(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (vec[i][j] == 0) continue;
			if (vec[i][j] < 5)
			{
				tmp[i][j] += vec[i][j];
				continue;
			}
			int dust = vec[i][j];
			int cnt = 0;
			int spread = dust / 5;
			for (int p = 0; p < 4; p++)
			{
				int nx = j + dx[p];
				int ny = i + dy[p];
				if (IsValid(nx, ny) && vec[ny][nx] != -1)
				{
					cnt++;
					tmp[ny][nx] += spread;
				}
			}
			tmp[i][j] += dust - (spread * cnt);
		}
	}
	vec = tmp;
}

void AirCleaner()
{
	vector<vector<int>> tmp(r, vector<int>(c, 0));
	tmp = vec;	
	int sx = up_x;
	int sy = up_y;
	tmp[sy][sx] = 0;
	tmp[sy+1][sx] = 0;
	int lx = c - 1;
	for (int i = sx; i < c -1 ; i++)
	{
		vec[sy][i+1] = tmp[sy][i];
	}
	for (int i = sy; i > 0; i--)
	{
		vec[i - 1][lx] = tmp[i][lx];
	}
	for (int i = lx; i > 0; i--)
	{
		vec[0][i - 1] = tmp[0][i];
	}
	for (int i = 0; i < sy -1; i++)
	{
		vec[i + 1][0] = tmp[i][0];
	}
	sy++;
	int ly = r - 1;
	for (int i = sx; i < c - 1; i++)
	{
		vec[sy][i + 1] = tmp[sy][i];
	}
	for (int i = sy; i < r-1; i++)
	{
		vec[i + 1][lx] = tmp[i][lx];
	}
	for (int i = lx; i > 0; i--)
	{
		vec[ly][i - 1] = tmp[ly][i];
	
	}
	for (int i = ly; i > sy - 1; i--)
	{
		vec[i - 1][0] = tmp[i][0];
	}
	vec[up_y][up_x] = -1;
	vec[up_y + 1][up_x] = -1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	cin >> r >> c >> t;
	vec.resize(r, vector<int>(c));
	
	bool flag = false;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> vec[i][j];
			if (vec[i][j] == -1 && !flag)
			{
				up_x = j;
				up_y = i;
				flag = true;
			}
		}
	}
	
	while (t--)
	{
		SpreadDust();
		AirCleaner();
		int a = 0;
	}
	int answer = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (vec[i][j] == -1) continue;

			answer += vec[i][j];
		}
	}
	cout << answer;
	return 0;
}
