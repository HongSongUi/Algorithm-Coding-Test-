#include <bits/stdc++.h>
using namespace std;

int n = 0;
int l = 0, r = 0;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
vector<vector<int>> arr;

bool IsVaild(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}
bool IsUnion(int val)
{
	return val >= l && val <= r;
}
bool bfs(int start_x, int start_y , vector<vector<bool>>& visited)
{
	queue<pair<int, int>> q;
	int total = 0;
	int count = 0;
	visited[start_y][start_x] = true;
	q.push(make_pair(start_y, start_x));
	queue<pair<int, int>> uni;
	total = 0;
	count = 0;
	while (!q.empty())
	{
		int cur_x = q.front().second;
		int cur_y = q.front().first;
		int cur_num = arr[cur_y][cur_x];
		uni.push(make_pair(cur_x, cur_y));
		total += cur_num;
		count++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (IsVaild(next_x, next_y) && !visited[next_y][next_x])
			{
				int next_num = arr[next_y][next_x];
				if (IsUnion(abs(next_num - cur_num)))
				{
					q.push(make_pair(next_y, next_x));
					visited[next_y][next_x] = true;
				}
			}
		}
	}
	if (uni.size() == 1) return false;

	while (!uni.empty())
	{
		int cur_x = uni.front().first;
		int cur_y = uni.front().second;
		arr[cur_y][cur_x] = total / count;
		uni.pop();
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n >> l >> r;
	arr.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	int days = 0;
	bool isFind = false;
	while (true)
	{
		vector<vector<bool>> visited(n, vector<bool>(n, false));
		bool moved = false;

		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++)
			{
				if (!visited[i][j]) 
				{
					if (bfs(j, i, visited))
					{
						moved = true;
					}
				}
			}
		}

		if (!moved) break;
		days++;
	
		
	}
	cout << days;
	return 0;
}