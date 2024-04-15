#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int time = 0;
	cin >> n;
	vector<int> buff(n);
	vector<int> total(n);
	for (int i = 0; i < n; i++)
	{
		cin >> buff[i];
	}
	sort(buff.begin(), buff.end());

	for (int i = 0; i < n; i++)
	{
		int num = buff[i];
		int sum = num;
		for (int j = 0; j < i; j++)
		{
			sum += buff[j];
		}
		total[i] = sum;
	}
	for (int i = 0; i < total.size(); i++)
	{
		time += total[i];
	}
	cout << time;
}