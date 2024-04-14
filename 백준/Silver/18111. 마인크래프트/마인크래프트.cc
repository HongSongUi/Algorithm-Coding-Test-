#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	int inventory = 0;
	cin >> n >> k >> inventory;
	int max_value = 0;
	int min_value = 257;
	vector<vector<int>> Land(n,vector<int>(k));
	map<int, int> BlockCount;

	int time = 99999999;
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> Land[i][j];
			BlockCount[Land[i][j]]++;
			if (Land[i][j] >= max_value)
			{
				max_value = Land[i][j];
			}
			if (Land[i][j] < min_value)
			{
				min_value = Land[i][j];
			}
		}
	}
	for (int i = min_value; i < max_value+1; i++)
	{
		int build = 0;
		int remove = 0;
		for (auto iter : BlockCount)
		{
			if (iter.first > i)
			{
				remove += (iter.second* (iter.first-i)) ;
			}
			else if (iter.first < i)
			{
				build += (iter.second* (i-iter.first));
			}
		}
		if ((remove + inventory) >= build)
		{
			int temp = remove * 2 + build;
			if (time > temp)
			{
				time = temp;
				result = i;
			}
			else if (time == temp)
			{
				result = i;
			}
		}
	}
	cout << time << " " << result;
}