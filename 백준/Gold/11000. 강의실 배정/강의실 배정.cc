#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<pair<int, int>> arr(n);
	int s = 0;
	int e = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e;
		arr[i] = make_pair(s, e);
	}
	sort(arr.begin(), arr.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(arr[0].second);
	for (int i = 1; i < n; i++)
	{
		s = arr[i].first;
		e = arr[i].second;
		if (s >= pq.top())
		{
			pq.pop();
		}
		pq.push(arr[i].second);
	}
	cout << pq.size();
	return 0;
}