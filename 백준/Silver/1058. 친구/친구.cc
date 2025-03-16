#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> arr;

bool FindFriend(int a, int b)
{
	bool isFriend = false;

	for (int i = 0; i < arr[a].size(); i++)
	{
		if (arr[a][i] == b)
		{
			isFriend = true;
		}
	}
	for (int i = 0; i < arr[a].size(); i++)
	{
		int num = arr[a][i];
		for (int j = 0; j < arr[num].size(); j++)
		{
			if (arr[num][j] == b)
			{
				isFriend = true;
			}
		}
	}


	return isFriend;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	cin >> n;
	arr.resize(n + 1);
	string s;
	int from, to;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		from = i;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'Y')
			{
				to = j + 1;
				arr[from].emplace_back(to);
			}
		}
	}
	int max_count = 0;
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (FindFriend(i, j))
			{
				count++;
			}
		}
		if (max_count < count)
		{
			max_count = count;
		}
		count = 0;
	}
	cout << max_count;
	return 0;
}