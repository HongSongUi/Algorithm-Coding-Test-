#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> dir = { {-1,0}, {0,1},{1,0},{0,-1} };

vector<vector<int>> lf = { {0,0,2,0,0}, {0,10,7,1,0},{5,0,0,0,0} , {0,10,7,1,0},{0,0,2,0,0} };
vector<vector<int>> btm = { {0,0,0,0,0},{0,1,0,1,0}, {2,7,0,7,2},{0,10,0,10,0}, {0,0,5,0,0} };
vector<vector<int>> rt = { {0,0,2,0,0} , {0,1,7,10,0}, {0,0,0,0,5}, {0,1,7,10,0}, {0,0,2,0,0} };
vector<vector<int>> up_d = { {0,0,5,0,0},{0,10,0,10,0},{2,7,0,7,2},{0,1,0,1,0} , {0,0,0,0,0} };
int n = 0;
vector<vector<int>> vec;

bool IsValid(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	vec.resize(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> vec[i][j];
		}
	}
	int cur_x = n / 2;
	int cur_y = n / 2;
	int idx = 0;
	int limit = 1;
	int answer = 0;
	while (true)
	{
		pair<int, int> cur_dir = dir[idx];
		vector<vector<int>> tmp;
		if (idx == 0) tmp = lf;
		else if (idx == 1) tmp = btm;
		else if (idx == 2) tmp = rt;
		else tmp = up_d;
		for (int p = 0; p < limit; p++)
		{
			int nx = cur_x + cur_dir.first;
			int ny = cur_y + cur_dir.second;
			int amount = vec[ny][nx];
			int dust = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (tmp[i][j] == 0) continue;
					
					int sx = nx + (j - 2);
					int sy = ny + (i - 2);
					int spread = amount * tmp[i][j]/100;
					dust += spread;
					if (IsValid(sx, sy))
					{
						vec[sy][sx] += spread;
						
					}
					else
					{
						answer += spread;
					}
				}
			}
			int alpha = amount - dust;
			vec[ny][nx] = 0;
			int ax = nx + cur_dir.first;
			int ay = ny + cur_dir.second;
			if (IsValid(ax, ay)) vec[ay][ax] += alpha;
			else answer += alpha;
			cur_x = nx;
			cur_y = ny;
			if (cur_x == 0 && cur_y == 0)
			{
				cout << answer;
				return 0;
			}
		}
		idx = (idx + 1) % 4;
		if (idx % 2 == 0) limit++;


	}
	return 0;
}
