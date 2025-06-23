#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = { {-1,0} ,{-1,-1},{0,-1},{1,-1} ,{1,0},{1,1},{0,1},{-1,1} }; // x,y
vector<pair<int, int>> diag = { {-1,-1},{1,-1},{1,1},{-1,1} }; // x,y
int n = 0, m = 0;
bool IsVaild(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
void MoveCloud(vector<vector<bool>>& cloud, vector<vector<int>>& arr ,int d, int s )
{
	vector<vector<bool>> tmp(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!cloud[i][j]) continue;

			int cur_x = j;
			int cur_y = i;
			pair<int, int> move = make_pair(dir[d].first * s, dir[d].second * s); // x,y;
			int next_x = cur_x + move.first;
			next_x %= n;
			if (next_x < 0)
			{
				next_x = n + next_x;		
			}
			int next_y = cur_y + move.second;
			next_y %= n;
			if (next_y < 0)
			{
				next_y = n + next_y;
			}
			
			tmp[next_y][next_x] = true;
		}
	}
	cloud = tmp; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!cloud[i][j]) continue;

			arr[i][j]++;
		}
	}
}
void CopyWater(vector<vector<bool>>& cloud, vector<vector<int>>& arr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!cloud[i][j]) continue;
			int cur_x = j;
			int cur_y = i;
			int cnt = 0;
			for (int p = 0; p < 4; p++)
			{
				int next_x = cur_x + diag[p].first;
				int next_y = cur_y + diag[p].second;
				if (IsVaild(next_x, next_y) && arr[next_y][next_x] > 0)
				{
					cnt++;
				}
			}
			arr[cur_y][cur_x] += cnt;
		}
	}
}
void CreateCloud(vector<vector<bool>>& cloud, vector<vector<int>>& arr)
{
	vector<vector<bool>> tmp(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] >= 2 && !cloud[i][j])
			{
				tmp[i][j] = true;
				arr[i][j] -= 2;
			}
		}
	}
	cloud = tmp;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(n, 0));
	vector<vector<bool>> cloud(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	queue<pair<int, int>>q; // dir, size
	int d = 0;
	int s = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> d >> s;
		q.push(make_pair(d-1, s));
	}
	cloud[n - 1][0] = true;
	cloud[n - 1][1] = true;
	cloud[n - 2][0] = true;
	cloud[n - 2][1] = true;
	while (!q.empty())
	{
		int cur_d = q.front().first;
		int cur_s = q.front().second;
		q.pop();
		MoveCloud(cloud, arr, cur_d, cur_s);
		CopyWater(cloud, arr);
		CreateCloud(cloud, arr);
		int a = 0;
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += arr[i][j];
		}
	}
	cout << answer;
	return 0;
}