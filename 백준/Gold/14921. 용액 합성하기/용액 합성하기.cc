#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<long long> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	int left = 0;
	int right = n - 1;
	long long min_val = LLONG_MAX;
	while (left < right)
	{
		long long cur = vec[left] + vec[right];
		if (abs(cur) < abs(min_val))
		{
			min_val = cur;
		}
		if (cur < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	cout << min_val;
	return 0;
}
