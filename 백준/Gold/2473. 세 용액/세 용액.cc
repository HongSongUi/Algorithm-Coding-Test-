#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int left = 0;
	int right = n - 1;
	long long min_val = LLONG_MAX;
	int res1 = 0, res2 = 0, res3 = 0;
	long long sum = 0;
	for (int i = 0; i < n-2; i++)
	{
		for (int j = i + 1; j < n-1; j++)
		{
			left = j+1;
			right = n - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;
				sum = arr[i] + arr[j] + arr[mid];
				if (abs(sum) < min_val)
				{
					min_val = abs(sum);
					res1 = arr[i];
					res2 = arr[j];
					res3 = arr[mid];
				}
				if (sum < 0)
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		}
	}
	cout << res1 <<' ' << res2 <<' ' << res3;
	return 0;
}