#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	while (n--)
	{
		int k = 0;
		cin >> k;
		priority_queue<long long,vector<long long>,greater<long long>> pq;
		long long num = 0;
		for (int i = 0; i < k; i++)
		{
			cin >> num;
			pq.push(num);
		}
		long long answer = 0;

		while (pq.size() > 1)
		{
			long long t1 = pq.top(); 
			pq.pop();
			long long t2 = pq.top();
			pq.pop();
			long long sum = t1 + t2;
			answer += sum;
			pq.push(sum);
		}
		cout << answer << '\n';
	}
	return 0;
}