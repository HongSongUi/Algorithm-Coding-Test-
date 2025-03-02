#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<vector<bool>> isOpen;
int n = 0;
vector<int> dx = { -1,0,1,0,-1,1,-1,1 };
vector<int> dy = { 0,-1,0,1,-1,-1,1,1 };

bool isValid(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

int MineFind(int x, int y)
{
	int count = 0;
	for (int i = 0; i < 8; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (isValid(next_x, next_y) && graph[next_y][next_x] == 1)
		{
			count++;
		}
	}
	return count;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	graph.resize(n, vector<int>(n));
	isOpen.resize(n, vector<bool>(n,false));
	bool isClick = false;
	char ch;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ch;
			if (ch == '.')
			{
				graph[i][j] = 0;
			}
			else if (ch == '*')
			{
				graph[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ch;
			if (ch == '.')
			{
				isOpen[i][j] = false;
			}
			else if (ch == 'x')
			{
				isOpen[i][j] = true;
				if (graph[i][j] == 1)
				{
					isClick = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (isOpen[i][j] == true)
			{
				if (graph[i][j] == 1)
				{
					cout << '*';
				}
				else
				{
					cout << MineFind(j, i);
				}
			}
			else
			{
				if (isClick && graph[i][j] == 1)
				{
					cout << '*';
				}
				else
				{
					cout << '.';
				}
			}
		}
		cout << '\n';
	}
	return 0;
}