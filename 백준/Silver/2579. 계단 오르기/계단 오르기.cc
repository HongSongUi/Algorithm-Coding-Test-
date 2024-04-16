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
	vector<int> max_buff(n + 1, 0);
	for (int i = 1; i <= n ; i++)
	{
		cin >> buff[i];
	}
	max_buff[1] = buff[1];
	max_buff[2] = buff[2]+buff[1];
	for (int i = 3; i <= n; i++)
	{
		max_buff[i] = max(buff[i] + buff[i - 1] + max_buff[i - 3], buff[i] + max_buff[i - 2]);
	}
	cout << max_buff[n];
}