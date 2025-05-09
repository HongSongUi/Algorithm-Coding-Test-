#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	int n = 0;
	while (t--)
	{
		cin >> n;
		vector<int> arr(n);
		long long answer = 0;
		int max_value = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		max_value = arr[n - 1];
		
		for (int i = n - 2; i >= 0; i--)
		{
			if (max_value > arr[i])
			{
				answer += max_value - arr[i];
			}
			else if (max_value < arr[i])
			{
				max_value = arr[i];
			}
		}
		cout << answer << '\n';
	}
	return 0;
}