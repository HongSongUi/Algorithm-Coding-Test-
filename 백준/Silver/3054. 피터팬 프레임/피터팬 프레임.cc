#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	cin >> s;
	int length = s.length()*4;
	vector<vector<char>> arr(5, vector<char>(length+1));

	int idx = 1;
	int start = 0;
	int mid = 2;
	int num = 0;
	while (idx <= s.length())
	{
		char ch = s[idx-1];
		for (int i = 0; i <5; i++)
		{
			for (int j = start; j < start+5; j++)
			{
				if (j == mid - num || j == mid + num)
				{
					if (idx % 3 == 0)
					{
						arr[i][j] = '*';
					}
					else
					{
						if (arr[i][j] != '*')
						{
							arr[i][j] = '#';
						}	
					}					
				}
				else
				{
					arr[i][j] = '.';
				}
				if (i == 2 && j == mid)
				{
					arr[i][j] = ch;
				}
			}
			if (i < 2)
			{
				num++;
			}
			else
			{
				num--;
			}
		}
		start += 4;
		idx++;
		num = 0;
		mid += 4;
	}
	
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr[0].size(); j++)
		{
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}