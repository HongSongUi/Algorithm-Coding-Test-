#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;
	unordered_map<string, int> tmp;
	string num = "";
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		tmp[num] = i;
	}
	priority_queue<pair<int, string>> pq;
	for (auto data : tmp)
	{
		pq.push(make_pair(-data.second, data.first));
	}
	int cnt = min(n, (int)pq.size());
	for (int i = 0; i < cnt; i++)
	{
		cout << pq.top().second << '\n';
		pq.pop();
	}
	return 0;
}
