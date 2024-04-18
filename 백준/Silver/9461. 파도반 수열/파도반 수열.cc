#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	int num = 0;
	vector<long long> buff(101);
	buff[0] = 0;
	buff[1] = 1;
	buff[2] = 1;
	buff[3] = 1;
	while (n > 0)
	{
		cin >> num;
		for (int i = 4; i < num+1; i++)
		{
			buff[i] = buff[i - 2] + buff[i - 3];
		}
		cout << buff[num] << "\n";
		n--;
	}
}