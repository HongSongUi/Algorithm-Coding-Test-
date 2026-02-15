#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct t
{
	int s = 0;
	int e = 0;
	t(int s, int e)
	{
		this->s = s;
		this->e = e;
	}
};
struct cmp
{
	bool operator()(t a, t b)
	{
		if (a.e == b.e) return a.s > b.s;
		return a.e > b.e;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	int s_t, e_t;

	priority_queue<t,vector<t>,cmp>pq;
	for (int i = 0; i < n; i++)
	{
		cin >> s_t >> e_t;
		pq.push(t(s_t, e_t));
	}
	int cnt = 0;
	int cur_time = 0;
	while (!pq.empty())
	{
		int s = pq.top().s;
		int e = pq.top().e;

		pq.pop();
		if (s >= cur_time)
		{
			cur_time = e;
			cnt++;
		}

	}

	cout << cnt;
	return 0;
}
