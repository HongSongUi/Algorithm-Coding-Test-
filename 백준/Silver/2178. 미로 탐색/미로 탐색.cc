#include <bits/stdc++.h>
using namespace std;

int N;
int M;
vector<vector<int>> buff;

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
bool CheckPoint(Point p)
{
	if ((p.x >= 0 && p.x < M) && (p.y >= 0 && p.y < N))
	{
		if (buff[p.y][p.x] != 0)
		{
			return true;
		}
	}
	return false;
}

void BFS(queue<pair<Point, int>>& q , vector<vector<bool>>& visit)
{
	vector<int> x_temp = { -1,0,1,0 };
	vector<int> y_temp = { 0,1,0,-1 };
	while (!q.empty())
	{
		Point cur = q.front().first;
		int count = q.front().second;
		q.pop();
		if ((cur.x == M - 1) && (cur.y == N - 1))
		{
			cout << count;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			Point p(cur.x + x_temp[i], cur.y + y_temp[i]);
	
			if (CheckPoint(p) && visit[p.y][p.x] == false)
			{
				int num = count + 1;
				q.push(make_pair(p, num));
				visit[p.y][p.x] = true;
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
	int count = 1;
	buff.resize(N,vector<int>(M,0));
	vector<vector<bool>> visit(N, vector<bool>(M, false));
	string temp = "";
	queue<pair<Point, int>> q;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			buff[i][j] = temp[j]- '0';
		}
	}
	Point p(0, 0);
	q.push(make_pair(p, count));
	visit[p.x][p.y] = true;
	BFS(q,visit);
}