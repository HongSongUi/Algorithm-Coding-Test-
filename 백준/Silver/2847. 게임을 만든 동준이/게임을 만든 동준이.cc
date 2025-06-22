#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int max_num = arr[n - 1];
	int answer = 0;
	for (int i = n - 2; i >= 0; i--)
	{
		int target = arr[i];
		if (target >= max_num)
		{
			int tmp = target-(max_num-1);
			answer = answer + tmp;
			target = max_num - 1;
		}

		arr[i] = target;
		max_num = arr[i];
	}
	cout << answer;
	return 0;
}