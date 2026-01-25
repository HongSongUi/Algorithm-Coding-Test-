#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int c = 0;
	cin >> n >> c;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end());

	long long low = 1;
	long long high = vec[n-1];

	long long answer = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cnt += (vec[i] / mid);
		}

		if (cnt >= c)
		{
			answer = max(mid, answer);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

	}
	cout << answer;
	return 0;
}
