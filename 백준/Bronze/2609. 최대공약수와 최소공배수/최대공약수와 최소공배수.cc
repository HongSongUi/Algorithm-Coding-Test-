#include <iostream>
using namespace std;

int main()
{
	int n, m = 0;
	int min, max = 0;
	cin >> n >> m;
	min = (n >= m) ? m : n;
	max = (n >= m) ? n : m;
	int r = 0;
	int g, l = 0;
	while (max % min != 0)
	{
		r = max % min;
		max = min;
		min = r;
	}
	g = min;
	l = (n * m) / g;
    cout <<g <<endl;
    cout<<l;
	return 0;
}