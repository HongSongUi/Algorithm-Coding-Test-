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
	buff[2] = 2;
	buff[3] = 3;
	for (int i = 4; i < n + 1; i++)
	{
		buff[i] = buff[i - 1] + 1;
		for (int j = 2; j * j < i+1; j++)
		{
			int temp = i - j * j;
			buff[i] = min(buff[i], buff[temp]);
		}
		buff[i]++;
	}
	cout << buff[n];	
}