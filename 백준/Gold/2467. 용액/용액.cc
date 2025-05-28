#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int min_val = INT_MAX;
	int left = 0;
	int right = n - 1;
	int num1 = 0;
	int num2 = 0;
	while (left<right)
	{
		int sum_value = arr[left] + arr[right];
		if (abs(sum_value) < min_val)
		{
			min_val = abs(sum_value);
			num1 = arr[left];
			num2 = arr[right];
		}

		if (sum_value < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	cout << num1 << ' ' << num2;
	return 0;
}