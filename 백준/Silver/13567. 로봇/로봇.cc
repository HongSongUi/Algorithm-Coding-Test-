#include <bits/stdc++.h>
using namespace std;
int m = 0;

bool isValid(int x, int y)
{
	return (x >= 0 && x <= m) && (y >= 0 && y <= m);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> m >> n;
	queue<pair<string, int>> q;
	string order = "";
	int value = 0;
	vector<pair<int, int>> dir = { {1,0}, {0,-1},{-1,0}, {0,1} };
	for (int i = 0; i < n; i++)
	{
		cin >> order >> value;
		q.push(make_pair(order, value));
	}
	int cur_x = 0;
	int cur_y = 0;
	int index = 0;
	pair<int, int> move_dir;

	while (!q.empty())
	{
		order = q.front().first;
		value = q.front().second;
		move_dir = dir[index];
		q.pop();
		if (order == "MOVE")
		{
			int next_x = cur_x + move_dir.first * value;
			int next_y = cur_y + move_dir.second * value;
			if (!isValid(next_x, next_y))
			{
				cout << -1;
				return 0;
			}
			else 
			{
				cur_x = next_x;
				cur_y = next_y;
			}
		}
		else if (order == "TURN")
		{
			if (value == 0)
			{
				index--;
				if (index < 0)
				{
					index = 3;
				}
			}
			else if (value == 1)
			{
				index++;
				index %= 4;
			}
		}
	}
	cout << cur_x << ' ' << cur_y;
	return 0;
}