#include <bits/stdc++.h>
#include <unordered_map>

#define INF 20000001
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;
	cin >> n >> m;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	long long low = 1;
	long long high = *max_element(vec.begin(), vec.end());
	long long answer = 0;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		long long cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if ((vec[i] - mid) > 0)
			{
				cnt += (vec[i] - mid);
			}
		}
		if (cnt >= m)
		{
			answer = mid;
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
