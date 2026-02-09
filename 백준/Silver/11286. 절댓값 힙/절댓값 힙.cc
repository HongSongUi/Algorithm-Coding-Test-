#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Number
{
	int num;
	int abs_num;
	Number()
	{
		num = 0;
		abs_num = 0;
	}
	Number(int n, int a)
	{
		num = n;
		abs_num = a;
	}
};
struct cmp
{
	bool operator()(Number a, Number b)
	{
		if (a.abs_num == b.abs_num) return a.num > b.num;
		return a.abs_num > b.abs_num;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<Number, vector<Number>, cmp> pq;
	int x = 0;
	while (n--)
	{
		cin >> x;
		if (x != 0)
		{
			pq.push(Number(x, abs(x)));
		}
		else if (x == 0)
		{
			if (pq.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << pq.top().num << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}
