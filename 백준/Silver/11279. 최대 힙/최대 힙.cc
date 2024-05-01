#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	priority_queue<int,vector<int>,cmp> q;
	int cmd = 0;
	while (n > 0)
	{
		cin >> cmd;
		if (cmd == 0)
		{
			if (q.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else
		{
			q.push(cmd);
		}
		n--;
	}
}