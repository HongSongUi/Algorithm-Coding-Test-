#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
bool Compare(Point a, Point b)
{
	if (a.x == b.x)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}
}

int main()
{
	int count = 0;
	int x, y = 0;
	cin >> count;
	vector<Point> coord(count);
	for (int i = 0; i < count; i++)
	{
		cin >> x >> y;
		Point p(x, y);
		coord[i] = p;
	}
	sort(coord.begin(), coord.end(), Compare);
	for (int i = 0; i < count; i++)
	{
		cout <<coord[i].x << " "<<coord[i].y<<"\n";
	}
}