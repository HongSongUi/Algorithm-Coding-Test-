#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0, k = 0;

vector<pair<int,int>> beers;

bool cmp(const pair<int,int>& a, const pair<int,int>& b)
{
	if (a.second < b.second) return true;
	else if (a.second == b.second) return a.first > b.first;
	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;

	beers.resize(k);

	priority_queue<int> pq;
	for (int i = 0; i < k; i++)
	{
		cin >> beers[i].first >> beers[i].second;
	}
	sort(beers.begin(), beers.end(), cmp);
	long long sum = 0;
	for (int i = 0; i < k; i++) {

		pq.push(-beers[i].first);
		sum += beers[i].first;

		if (pq.size() > n) {
			sum += pq.top();
			pq.pop();
		}


		if (pq.size() == n && sum >= m) {
			cout << beers[i].second;
			return 0;
		}
	}

	cout << -1;
	return 0;
}