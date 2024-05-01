#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M = 0;
	cin >> N >> M;
	vector<int> buff(N);
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> buff[i];
	}
	sort(buff.begin(), buff.end());
	int start = 0;
	int end = buff[N - 1];
	int mid = 0;
	int result = 0;
	while (start <= end)
	{
		sum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++)
		{
			if (buff[i] >= mid)
			{
				sum += buff[i] - mid;
			}
		}
		if (sum >= M)
		{
			result = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	cout << result;
}