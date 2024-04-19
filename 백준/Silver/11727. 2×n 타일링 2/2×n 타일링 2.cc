#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> buff(n + 1, 0);
	buff[1] = 1;
	buff[2] = 3;
	for (int i = 3; i < n + 1; i++)
	{
		if (i % 2 == 0)
		{
			buff[i] = (buff[i - 1] * 2) + 1;
			buff[i] %= 10007;
		}
		else
		{
			buff[i] = (buff[i - 1] * 2) - 1;
			buff[i] %= 10007;
		}
	}
	cout << buff[n];
}