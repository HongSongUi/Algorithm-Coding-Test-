#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, c = 0;
	cin >> n >> c;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int answer = 1;
	int min_length = 1;
	int max_length = arr[n - 1] - arr[0];
	while (min_length <= max_length)
	{
		int length = (min_length + max_length) / 2;
		int tmp = 1;
		int cur_idx = arr[0];
		for (int i = 1; i < n; i++)
		{
			if (arr[i] >= cur_idx + length)
			{
				tmp++;
				cur_idx = arr[i];
			}
		}
		if (tmp >= c)
		{
			answer = max(answer, length);
			min_length = length + 1;
		}
		else
		{
			max_length = length - 1;
		}
	}
	cout << answer;
	return 0;
}