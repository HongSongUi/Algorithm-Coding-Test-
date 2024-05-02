#include <bits/stdc++.h>
using namespace std;

int N;
int M;
vector<vector<int>> Campus;
vector<vector<bool>> Visit;
queue<pair<int, int>> q;

bool Check(int x, int y)
{
	if ((x >= 0 && x < M) && (y >= 0 && y < N))
	{
		if (Campus[y][x] != -1)
		{
			return true;
		}
	}
	return false;
}

void FindPeple(int start_x, int start_y, int& count)
{
	q.push(make_pair(start_x, start_y));
	Visit[start_y][start_x] = true;
	vector<int> x = { 0,0,-1,1 };
	vector<int> y = { -1,1,0,0 };
	while (!q.empty())
	{
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		if (Campus[cur_y][cur_x] == 2)
		{
			count++;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int x_temp = cur_x + x[i];
			int y_temp = cur_y + y[i];
			if (Check(x_temp, y_temp) && !Visit[y_temp][x_temp] )
			{
				q.push(make_pair(x_temp, y_temp));
				Visit[y_temp][x_temp] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	string temp = "";
	Campus.resize(N, vector<int>(M, 0));
	Visit.resize(N, vector<bool>(M, false));
	int start_x = 0;
	int start_y = 0;
	int meet_count = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.size(); j++)
		{
			if (temp[j] == 'O')
			{
				Campus[i][j] = 0;
			}
			else if (temp[j] == 'X')
			{
				Campus[i][j] = -1;
			}
			else if (temp[j] == 'P')
			{
				Campus[i][j] = 2;
			}
			else
			{
				Campus[i][j] = 1;
				start_x = j;
				start_y = i;
			}
		}
	}
	FindPeple(start_x, start_y, meet_count);
	if (meet_count == 0)
	{
		cout << "TT";
	}
	else
	{
		cout << meet_count;
	}
}