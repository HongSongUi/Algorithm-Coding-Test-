#include <bits/stdc++.h>
using namespace std;
int gcd(int num1, int num2)
{

	int num3 = 0;
	while (num2 != 0)
	{
		num3 = num1 % num2;
		num1 = num2;
		num2 = num3;
	}
	return num1;
}
int lcm(int num1, int num2)
{
	return num1 * num2 / gcd(num1, num2);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int count = 0;
	cin >> count;
	int n, m = 0;
	int x, y = 0;
	int y_temp = 0;
	int year = -1;
	int limit = 0;
	while (count > 0)
	{
		year = -1;
		cin >> n >> m >> x >> y;
		limit = lcm(n, m);
		for (int i = x; i <= limit; i+=n)
		{
			y_temp = i % m;
			if (y_temp == 0)
			{
				y_temp = m;
			}
			if (y_temp == y)
			{
				year = i;
				break;
			}
		}
		count--;
		cout << year << "\n";
	}
}