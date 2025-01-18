#include <bits/stdc++.h>
using namespace std;

int R, C;

vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,1,0,-1 };
struct Point
{
	int x = 0;
	int y = 0;
};

bool CheckPoint(int x, int y)
{
	if ((x >= 0 && x < C) && (y >= 0 && y < R))
	{
		return true;
	}
	return false;
}

int DSF(int cur_x, int cur_y ,vector<vector<char>>& board, vector<bool>& alphbet)
{
	int max_depth = 1;

	for (int i = 0; i < 4; i++)
	{
		int next_x = cur_x + dx[i];
		int next_y = cur_y + dy[i];
		if (CheckPoint(next_x, next_y))
		{
			int num = board[next_y][next_x] - 'A';
			if (alphbet[num] == false)
			{
				alphbet[num] = true;
				max_depth = max(max_depth, 1 + DSF(next_x, next_y, board, alphbet));
				alphbet[num] = false;
			}
		}
	}
	return max_depth;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> R >> C;
	vector<vector<char>> board(R, vector<char>(C));
	string temp;
	for (int i = 0; i < R; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			board[i][j] = temp[j];
		}
	}
	vector<bool> alphbet(26, false);

	alphbet[board[0][0] - 'A'] = true;
	int answer = DSF(0, 0, board, alphbet);
	cout << answer;

	return 0;
}