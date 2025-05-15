#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	deque<int> dq;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}
	while (dq.size() > k)
	{
		int num = dq.front();
		for (int i = 0; i < k; i++)
		{
			dq.pop_front();
		}
		dq.push_back(num);
	}
	cout << dq.front();
	return 0;
}