#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> buff(11,0);
	buff[1] = 1;
	buff[2] = 2;
	buff[3] = 4;
	int num = 0;
	while (n > 0)
	{
		cin >> num;
		for (int i = 4; i < num+1; i++)
		{
			buff[i] = buff[i - 3] + buff[i - 1] + buff[i - 2];
		}
		cout << buff[num] << "\n";
		n--;
	}
}