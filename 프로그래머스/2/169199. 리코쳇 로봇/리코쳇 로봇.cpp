#include <bits/stdc++.h>

using namespace std;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
int lx = 0;
int ly = 0;
struct Point
{
	int x = 0;
	int y = 0;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};
bool IsValid(int x, int y)
{
	return (x >= 0 && x < lx) && (y >= 0 && y < ly);
}

int BFS(int sx, int sy, int ex, int ey,vector<vector<int>>& board)
{
	int ret = -1;
	vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
	visited[sy][sx] = true;
	queue<pair<Point, int>> q;
	q.push(make_pair(Point(sx, sy), 0));
	while(!q.empty())
	{
		int cur_x = q.front().first.x;
		int cur_y = q.front().first.y;
		int cur_depth = q.front().second;
		q.pop();
		
		if (cur_x == ex && cur_y == ey)
		{
			ret = cur_depth;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			if (IsValid(cur_x + dx[i], cur_y + dy[i]) && board[cur_y + dy[i]][cur_x + dx[i]] != -1)
			{
				int nx = cur_x + dx[i];
				int ny = cur_y + dy[i];
				while (true)
				{
					if (!IsValid(nx+dx[i], ny+dy[i]) || board[ny+dy[i]][nx+dx[i]] == -1) break;
					ny += dy[i];
					nx += dx[i];
				}
				if (!visited[ny][nx])
				{
					visited[ny][nx] = true;
					q.push(make_pair(Point(nx, ny), cur_depth + 1));
				}
			}
		}

	}
	return ret;
}
int solution(vector<string> board) 
{
    vector<vector<int>> vec(board.size(), vector<int>(board[0].length()));
	lx = vec[0].size();
	ly = vec.size();
	int sx = 0;
	int sy = 0;
	int ex = 0;
	int ey = 0;
	for (int i = 0; i < board.size(); i++)
	{
		string tmp = board[i];
		for (int j = 0; j < tmp.length(); j++)
		{
			if (tmp[j] == '.')
			{
				vec[i][j] = 0;
			}
			else if (tmp[j] == 'D')
			{
				vec[i][j] = -1;
			}
			else if (tmp[j] == 'G')
			{
				vec[i][j] = 2;
				ex = j;
				ey = i;
			}
			else if (tmp[j] == 'R')
			{
				vec[i][j] = 0;
				sx = j;
				sy = i;
			}
		}
	}
	
	int answer = BFS(sx, sy, ex, ey, vec);
    return answer;
}