#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> tmp;
vector<vector<bool>> selected;
vector<vector<int>> arr;
int answer = 0;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
bool IsValid(int x, int y)
{
	return (x >= 0 && x < 5) && (y >= 0 && y < 5);
}
bool BFS()
{
	int start_x = tmp[0].second;
	int start_y = tmp[0].first;
	vector<vector<bool>>visited(5, vector<bool>(5,false));
	vector<vector<bool>> target(5, vector<bool>(5, false));
	for (int i = 0; i < tmp.size(); i++)
	{
		target[tmp[i].first][tmp[i].second] = true;
	}
	queue<pair<int, int>> q;
	q.push(make_pair(start_y, start_x));
	visited[start_y][start_x] = true;
	int count = 1;
	while(!q.empty())
	{
		int cur_x = q.front().second;
		int cur_y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];
			if (IsValid(next_x, next_y) && !visited[next_y][next_x] && target[next_y][next_x])
			{
				visited[next_y][next_x] = true;
				q.push(make_pair(next_y, next_x));
				count++;
			}
		}
	}
	return count == 7;
}
void Func(int count, int val,int idx)
{
	if (count == 7)
	{
		if (BFS() && val > 0)
		{
			answer++;
		}
		return;
	}
	for (int i = idx; i < 25; i++)
	{
		int y = i / 5;
		int x = i % 5;
		if (!selected[y][x])
		{
			selected[y][x] = true;
			tmp.emplace_back(y, x);
			Func(count + 1, val + arr[y][x], i + 1);
			selected[y][x] = false;
			tmp.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	string tmp = "";
	arr.resize(5, vector<int>(5));
	selected.resize(5, vector<bool>(5, false));
	for (int i = 0; i < 5; i++)
	{
		cin >> tmp;
		for (int j = 0; j < 5; j++)
		{
			int num = tmp[j] == 'Y' ? -1 : 1;
			arr[i][j] = num;
		}
	}
	Func(0, 0,0);
    cout << answer;
	return 0;
}