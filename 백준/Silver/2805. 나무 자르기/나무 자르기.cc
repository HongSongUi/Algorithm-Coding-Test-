#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	vector<int> trees(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> trees[i];
	}
	sort(trees.begin(), trees.end());
	int left = 0;
	int right = trees[n - 1];
	long long answer = 0;
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long total = 0;
		for (int i = 0; i < n; i++)
		{
			if (trees[i] >= mid) 
			{
				total += trees[i] - mid;
			}
		}
		if (total >= m)
		{
			answer = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << answer;
	return 0;
}