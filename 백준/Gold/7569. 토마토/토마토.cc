#include <bits/stdc++.h>
using namespace std;
int M, N, H;
vector<vector<vector<int>>> box;
struct Point
{
	int x;
	int y;
	int z;
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point(int x, int y,int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

bool Check(Point& p)
{
	if ((p.x >= 0 && p.x < M) && (p.y >= 0 && p.y < N ) && (p.z>=0&& p.z<H))
	{
		return true;
	}
	return false;
}
void BFS(queue<pair<Point, int>>& q, int& zero_count, int& time)
{
	vector<int> dx = { 0, 0, -1, 1, 0, 0 };
	vector<int> dy = { -1, 1, 0, 0, 0, 0 }; 
	vector<int> dz = { 0, 0, 0, 0, -1, 1 };
	while (!q.empty())
	{
		Point point = q.front().first;
		int depth = q.front().second;
		time = depth;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			Point p(point.x + dx[i], point.y + dy[i],point.z+dz[i]);
			if (Check(p) && box[p.z][p.y][p.x] == 0)
			{
				zero_count--;
				box[p.z][p.y][p.x] = 1;
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
	

	cin >> M >> N >> H;
	box.resize(H, vector<vector<int>>(N, vector<int>(M)));
	queue<pair<Point, int>> q;
	int time = 0;
	int zero_count = 0;

	for (int z = 0; z < H; z++) 
	{
		for (int y = 0; y < N; y++) 
		{ 
			for (int x = 0; x < M; x++) 
			{ 
				cin >> box[z][y][x];
				if (box[z][y][x] == 0) 
				{
					zero_count++;
				}
				else if (box[z][y][x] == 1) 
				{
					q.push({ Point(x, y, z), 0 });
				}
			}
		}
	}
	BFS(q, zero_count, time);
	if (zero_count == 0)	cout << time;
	else cout << -1;
}