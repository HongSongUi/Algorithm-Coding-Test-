#include <bits/stdc++.h>

using namespace std;
vector<vector<string>> vec;
vector<vector<bool>> visited;
vector<pair<int, int>> arr;
int answer = 0;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
bool IsValid(int x, int y)
{
	return (x >= 0 && x < 5) && (y >= 0 && y < 5);
}
bool BFS()
{
	vector<vector<bool>> tmp(5, vector<bool>(5));
	queue<pair<int, int>> q;
	q.push(arr[0]);
	tmp[arr[0].first][arr[0].second] = true;
	int cnt = 1;
	while (!q.empty())
	{
		int cur_x = q.front().second;
		int cur_y = q.front().first;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];
			if (IsValid(nx, ny) && !tmp[ny][nx] && visited[ny][nx])
			{
				q.push(make_pair(ny, nx));
				tmp[ny][nx] = true;
				cnt++;
			}

		}

	}
	return cnt == 7;
}

void Choose(int cnt ,int idx , int num)
{
	int y_cnt = cnt - num;
	if (y_cnt >= 4)
	{
		return;
	}
	if (cnt == 7)
	{
		if (num >= 4 && BFS())
		{
			answer++;
		}
		return;
	}

	for (int i = idx; i < 25; i++)
	{
		int y = i / 5;
		int x = i % 5;
		if (!visited[y][x])
		{
			
			arr.emplace_back(make_pair(y, x));
			visited[y][x] = true;
		
			Choose(cnt + 1, i + 1, num + (vec[y][x] == "S"));
			
			visited[y][x] = false;
			arr.pop_back();
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vec.resize(5, vector<string>(5));
	visited.resize(5, vector<bool>(5));
	string str = "";
	for (int i = 0; i < 5; i++)
	{
		cin >> str;
		for (int j = 0; j < 5; j++)
		{
			vec[i][j] = str[j];
		}
	}

	Choose(0, 0, 0);
	cout << answer;
	return 0;
}
