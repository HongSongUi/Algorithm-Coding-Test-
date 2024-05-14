#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> buff;

bool CheckPoint(int x, int y)
{
	if ((x >= 0 && x < N) && (y >= 0 && y < N))
	{
		if (buff[y][x] == 1)
		{
			return true;
		}
	}
	return false;
}

void BFS(queue<pair<int, int>>& q, vector<vector<bool>>& visit, int& count)
{
	vector<int> x_temp = { -1,0,1,0 };
	vector<int> y_temp = { 0,1,0,-1 };
	while (!q.empty())
	{
		int cur_y = q.front().first;
		int cur_x = q.front().second;
		count++;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x = cur_x + x_temp[i];
			int y = cur_y + y_temp[i];
			if (CheckPoint(x, y) && visit[y][x] == false)
			{
				q.push(make_pair(y, x));
				visit[y][x] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	buff.resize(N, vector<int>(N));
	vector<vector<bool>> visit(N, vector<bool>(N, false));
	string temp = "";
	vector<int> apart;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			buff[i][j] = temp[j] - '0';
		}
	}
	int num = 0;
	int count = 0;
	queue<pair<int, int>>q;
	for (int i = 0; i < N; i++)
	{
		count = 0;
		for (int j = 0; j < N; j++)
		{
			num = buff[i][j];
			if (num == 1 && visit[i][j] == false)
			{
				q.push(make_pair(i, j));
				visit[i][j] = true;
				BFS(q, visit, count);
				apart.emplace_back(count);
				count = 0;
			}
		}
	}
	sort(apart.begin(), apart.end());
	cout << apart.size() << "\n";
	for (int i = 0; i < apart.size(); i++)
	{
		cout << apart[i] << "\n";
	}
}