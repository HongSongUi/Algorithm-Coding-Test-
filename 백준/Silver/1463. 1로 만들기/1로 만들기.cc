#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> buff(n+1, 0);
	buff[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		buff[i] = buff[i - 1] + 1;
		if (i % 3 == 0)
		{
			buff[i] = min(buff[i / 3] + 1, buff[i]);
		}
		if (i % 2 == 0)
		{
			buff[i] = min(buff[i / 2] + 1, buff[i]);
		}
	}
	cout << buff[n];
}