#include <bits/stdc++.h>
using namespace std;

struct Point 
{
	int x, y;
	Point()
	{
		x = 0;
		y = 0;
	}
};

bool Compair(Point & a , Point& b)
{
	if (a.y == b.y)
	{
		return a.x<b.x;
	}
	return a.y < b.y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<Point> temp(n);

	for (int i = 0; i < n; i++)
	{
		cin >> temp[i].x >> temp[i].y;
	}
	sort(temp.begin(), temp.end(), Compair);
	
	for (int i = 0; i < n; i++)
	{
		cout << temp[i].x << " " << temp[i].y << "\n";
	}
}