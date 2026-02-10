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
	priority_queue<int,vector<int>, greater<int>> pq;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		pq.push(tmp);
	}
	int answer = 0;
	while (pq.size() >1)
	{
		int n1 = pq.top();
		pq.pop();

		int n2 = pq.top();
		
		pq.pop();
		answer += n1 + n2;
		
		pq.push(n1 + n2);
	}
	cout << answer;
	return 0;
}
