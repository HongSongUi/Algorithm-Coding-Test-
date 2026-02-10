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
	int num = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		if (num == 0)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(num);
		}
	}

	return 0;
}
