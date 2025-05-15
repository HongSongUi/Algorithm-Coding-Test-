#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	priority_queue<int> pq;
	int num = 0;
	cin >> num;
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	int tmp = 0;
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}
	int count = 0;
	while (true)
	{
		if (num > pq.top())
		{
			break;
		}
		int cur_top = pq.top() - 1;
		pq.pop();
		num++;
		pq.push(cur_top);
		count++;
	}
	cout << count;
	return 0;
}