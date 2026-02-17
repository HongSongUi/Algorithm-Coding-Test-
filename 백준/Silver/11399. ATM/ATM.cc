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
	
	priority_queue<int,vector<int>,greater<int>> pq;

	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		pq.push(t);
	}
	int tmp = 0;
	int answer = 0;

	while (!pq.empty())
	{
		tmp += pq.top();
		answer += tmp;
		pq.pop();
	}
	cout << answer;
	return 0;
}
