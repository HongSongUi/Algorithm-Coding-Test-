#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>& board, vector<bool> visit, int& time)
{
	queue<pair<int, int>> q;
	q.push(make_pair(1, time));
	visit[1] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		int t = q.front().second;
		q.pop();
		for (int i = 1; i < 7; i++)
		{
			int next = cur + i;

			if (next == 100)
			{
				time = t + 1;
				return;
			}
			
			else if (next < 100)
			{
				if (board[next] != 0)
				{
					next = board[next];
				}
				if (visit[next] == false)
				{
					q.push(make_pair(next, t + 1));
					visit[next] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> board(101, 0);
	vector<bool> visit(101, false);
	
	int cur = 0;
	int move = 0;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> cur >> move;
		board[cur] = move;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> cur >> move;
		board[cur] = move;
	}
	bfs(board, visit, time);
	cout << time;
}
