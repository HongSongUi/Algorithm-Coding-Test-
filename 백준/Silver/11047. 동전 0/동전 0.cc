#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	cin >> n >> k;
	int money = 0;
	int count = 0;
	vector<int> buff(n);
	for (int i = 0; i < n; i++)
	{
		cin >> buff[i];
	}
	for (int i = buff.size() - 1; i >= 0; i--)
	{
		if (money+buff[i] > k)
		{
			continue;
		}
		while (true)
		{
			money += buff[i];
			count++;
			if (money + buff[i] > k)
			{
				break;
			}
		}
		if (money == k)
		{
			break;
		}
	}
	cout << count;
}