#include <bits/stdc++.h>
#include <unordered_map>

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
	sort(vec.begin(), vec.end());
	int r1 = 0;
	int r2 = 0;
	int r3 = 0;

	long long min_sum = LLONG_MAX;

	for (int i = 0; i < n - 2 ; i++)
	{
		long long n1 = vec[i];
		int left = i + 1;
		int right = n - 1;
		while (left < right)
		{
			long long sum = n1 + vec[left] + vec[right];
			if (min_sum > abs(sum))
			{
				r1 = n1;
				r2 = vec[left];
				r3 = vec[right];
				min_sum = abs(sum);
			}

			if (sum < 0)
			{
				left++;
			}
			else
			{
				right--;
			}
		}
	}
	cout << r1 << ' ' << r2 << ' ' << r3;
	return 0;
}
