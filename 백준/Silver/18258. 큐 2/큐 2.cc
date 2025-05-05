#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	string order = "";
	int num = 0;
	deque<int> dq;
	while (n--)
	{
		cin >> order;
		if (order == "push")
		{
			cin >> num;
			dq.push_back(num);
		}
		else if (order == "pop")
		{
			if (dq.size() == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (order == "size")
		{
			cout << dq.size()<<'\n';
		}
		else if (order == "empty")
		{
			cout << dq.empty() ? 1 : 0;
			cout << '\n';
		}
		else if (order == "front")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.front() << '\n';
			}
		}
		else if (order == "back")
		{
			if (dq.empty())
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << dq.back() <<'\n';
			}
		}
	}
	return 0;
}