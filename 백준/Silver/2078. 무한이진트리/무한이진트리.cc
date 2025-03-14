#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a = 0, b = 0;
	cin >> a >> b;
	
	int left = 0;
	int right = 0;
	while (true)
	{
		if (a == 1)
		{
			right += b - 1;
			break;
		}
		else if (b == 1)
		{
			left += a - 1;
			break;
		}
		if (a > b)
		{
			left += a / b;
			a %= b;
		}
		else if (a < b)
		{
			right += b / a;
			b %= a;
		}

	}
	cout << left <<" " <<right;
	return 0;
}