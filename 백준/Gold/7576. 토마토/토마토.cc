#include <bits/stdc++.h>
using namespace std;

int m;
int n;
vector<vector<int>> Box;
struct Point
{
	int x;
	int y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool Check(Point& p)
{
	if ((p.x >= 0 && p.x < m) && (p.y >= 0 && p.y < n))
	{
		return true;
	}
	return false;
}

void BFS(queue<pair<Point, int>>& q, int& zero_count,int& time)
{
	vector<int> x = { 0,0,-1,1 };
	vector<int> y = { -1,1,0,0 };
	while (!q.empty())
	{
		Point point = q.front().first;
		int depth = q.front().second;
		time = depth;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point p(point.x + x[i], point.y + y[i]);
			if (Check(p) && Box[p.y][p.x] ==0)
			{
				zero_count--;
				Box[p.y][p.x] = 1;
				q.push(make_pair(p, depth + 1));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n;
	Box.resize(n, vector<int>(m, 0));
	queue<pair<Point,int>> q;
	int zero_count = 0;
	int time = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> Box[i][j];
			if (Box[i][j] == 0)
			{
				zero_count++;
			}
			else if (Box[i][j] == 1)
			{
				Point p(j,i);
				q.push(make_pair(p, 0));
			}
		}
	}
	BFS(q, zero_count, time);
	if (zero_count == 0)	cout << time;
	else cout << -1;
}