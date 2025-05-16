#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	set<int> lines;
	vector<int> arr;
	
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		lines.insert(num);
		arr.emplace_back(num);
	}

	int answer = 0;
	for (auto remove_val : lines)
	{
		vector<int> tmp;
		for (int i = 0; i < arr.size(); i++)
		{
			if (arr[i] != remove_val)
			{
				tmp.emplace_back(arr[i]);
			}
		}
		int max_count = 1;
		int len = 1;
		for (int i = 1; i < tmp.size(); i++)
		{
			if (tmp[i] == tmp[i - 1])
			{
				len++;
			}
			else
			{
				len = 1;
			}
			max_count = max(max_count, len);
		}
		answer = max(answer, max_count);
	}
	cout << answer;
	return 0;
}