#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = { {0,-1} ,{-1,-1},{-1,0},{-1,1} ,{0,1},{1,1},{1,0},{1,-1} }; // x,y

int answer = 0;

struct Fish 
{
	int num, dir;
};


bool IsVaild(int x, int y)
{
	return (x >= 0 && x < 4) && (y >= 0 && y < 4);
}

void MoveFish(vector<vector<Fish>>& arr, int shark_x, int shark_y)
{
	
	for (int f = 1; f <= 16; f++)
	{
		int cur_x = -1;
		int cur_y = -1;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j].num == f)
				{
					cur_x = j;
					cur_y = i;
					break;
				}
			}
			if (cur_x!= -1) break;
		}
		if (cur_x == -1) continue;


		int d = arr[cur_y][cur_x].dir;

		for (int i = 0; i < 8; i++)
		{
			int next_x = cur_x + dir[d].first;
			int next_y = cur_y + dir[d].second;
			if (IsVaild(next_x, next_y) && !(next_x == shark_x && next_y == shark_y))
			{
				swap(arr[cur_y][cur_x], arr[next_y][next_x]);
				arr[next_y][next_x].dir = d;
				break;
			}
			d = (d + 1) % 8;
		}
	}
}
void DFS(int x, int y, int shark_dir, int total, vector<vector<Fish>> arr)
{
	MoveFish(arr, x, y);
	answer = max(answer, total);
	int nx = x;
	int ny = y;
	while (true)
	{
		nx += dir[shark_dir].first;
		ny += dir[shark_dir].second;
		if (!IsVaild(nx, ny)) break;

		if (arr[ny][nx].num != 0)
		{
			vector<vector<Fish>> cpy = arr;
			int n = cpy[ny][nx].num;
			int newDir = cpy[ny][nx].dir;

			cpy[ny][nx] = { 0,0 };

			DFS(nx, ny, newDir, total + n, cpy);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	vector<vector<Fish>> arr(4, vector<Fish>(4));

	int val;
	int d;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> val >> d;
			arr[i][j] = { val,d - 1 };
	
		}
	}	

	int n = arr[0][0].num;
	int shark_dir = arr[0][0].dir;
	arr[0][0] = { 0,0 };

	DFS(0, 0, shark_dir, n, arr);

	
	cout << answer;
	return 0;
}