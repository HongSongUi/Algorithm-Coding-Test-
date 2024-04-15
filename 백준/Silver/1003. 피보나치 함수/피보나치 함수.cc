#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int num = 0;
	cin >> n;
	int zero_count = 0;
	int one_count = 0;
	vector<vector<int>> buff(41, vector<int>(2));
	buff[0][0] = 1;
	buff[0][1] = 0;
	buff[1][0] = 0;
	buff[1][1] = 1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		for (int j = 2; j <= num; j++)
		{
			buff[j][0] = buff[j - 1][0] + buff[j - 2][0];
			buff[j][1] = buff[j - 1][1] + buff[j - 2][1];
		}
		cout << buff[num][0] << " " << buff[num][1] << "\n";
	}
}