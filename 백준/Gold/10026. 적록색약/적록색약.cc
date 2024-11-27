#include <bits/stdc++.h>
using namespace std;

int num;
vector<vector<string>>paint;
vector<vector<string>> rg_paint;
vector<vector<bool>> r_visit;
vector<vector<bool>> rg_visit;

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
	if ((p.x >= 0 && p.x < num) && (p.y >= 0 && p.y < num))
	{
		return true;
	}
	return false;
}

void R_BFS(int& r_count, string target,Point p)
{
	vector<int> x = { 0,0,-1,1 };
	vector<int> y = { -1,1,0,0 };
	queue<Point> r_qu;
	r_qu.push(p);
	r_visit[p.y][p.x] = true;
	while (!r_qu.empty())
	{
		Point point = r_qu.front();
		r_qu.pop();
		
		for (int i = 0; i < 4; i++)
		{
			Point next(point.x + x[i], point.y + y[i]);
			if (Check(next) && paint[next.y][next.x] == target)
			{
				if (r_visit[next.y][next.x] == false)
				{
					r_visit[next.y][next.x] = true;
					r_qu.push(next);
				}		
			}
		}
	}
	r_count++;
}
void RG_BFS(int& rg_count, string target, Point p)
{
	vector<int> x = { 0,0,-1,1 };
	vector<int> y = { -1,1,0,0 };
	queue<Point> rg_qu;
	rg_qu.push(p);
	rg_visit[p.y][p.x] = true;
	while (!rg_qu.empty())
	{
		Point point = rg_qu.front();
		rg_qu.pop();
		
		for (int i = 0; i < 4; i++)
		{
			Point next(point.x + x[i], point.y + y[i]);
			if (Check(next) && rg_paint[next.y][next.x] == target)
			{
				if (rg_visit[next.y][next.x] == false)
				{
					rg_visit[next.y][next.x] = true;
					rg_qu.push(next);
				}
			}
		}
	}
	rg_count++;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> num;
	paint.resize(num, vector<string>(num));
	rg_paint.resize(num, vector<string>(num));
	r_visit.resize(num, vector < bool >(num));
	rg_visit.resize(num, vector<bool>(num));
	int area = 0;
	int r_count = 0;
	int rg_count = 0;
	string temp = "";
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		for (int j = 0; j < temp.length(); j++)
		{
			paint[i][j] = temp[j];
			if (temp[j] == 'G')
			{
				rg_paint[i][j] = 'R';
			}
			else
			{
				rg_paint[i][j] = temp[j];
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			
			Point p(j, i);
			if (r_visit[i][j] == false)
			{
				string target = paint[i][j];
				R_BFS(r_count, target, p);
			}
			if (rg_visit[i][j] == false)
			{
				string target = rg_paint[i][j];
				RG_BFS(rg_count, target, p);
			}
		}
	}
	cout << r_count << " " << rg_count;
	int a = 0;
}