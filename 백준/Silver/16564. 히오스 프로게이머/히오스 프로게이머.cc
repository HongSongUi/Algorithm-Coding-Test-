#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0, k = 0;
	cin >> n >> k;
	vector<long long> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	long long answer = 0;
	long long diff = 0;
	long long num = 0;
	while (true)
	{
		long long tmp = arr[0];
		num = upper_bound(arr.begin(), arr.end(), tmp) - arr.begin();
		if (num == n)
		{
			answer = tmp + k / num;
			break;
		}
		diff = arr[num] - tmp;
		if (diff * num <= k)
		{
			arr[0] += diff;
		}
		else
		{
			answer = tmp + k / num;
			break;
		}
		k -= diff * num;
	}
	cout << answer;
	return 0;
}