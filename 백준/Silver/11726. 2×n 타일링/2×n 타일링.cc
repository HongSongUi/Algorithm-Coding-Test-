#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<long long> buff(n+1,0);
	buff[1] = 1;
	buff[2] = 2;
	for (int i = 3; i < n + 1; i++)
	{
		buff[i] = buff[i - 1] + buff[i - 2];
		buff[i] %= 10007;
	}
	cout << buff[n];
}