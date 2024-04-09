#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int count = 0;
	cin >> n;
	int num = 0;	
	string temp = "";
	deque<int> buff;
	while (count < n)
	{
		cin >> temp;
		if (temp == "push_front")
		{
			cin >> num;
			buff.push_front(num);
		}
		else if (temp == "push_back")
		{
			cin >> num;
			buff.push_back(num);
		}
		else if (temp == "pop_front")
		{
			if (buff.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << buff.front() << "\n";
				buff.pop_front();
			}
		}
		else if (temp == "pop_back")
		{
			if (buff.size() == 0)
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << buff.back() << "\n";
				buff.pop_back();
			}
		}
		else if (temp == "size")
		{
			cout << buff.size() << "\n";
		}
		else if (temp == "empty")
		{
			if (buff.empty())
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (temp == "front")
		{
			if (buff.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << buff.front() << "\n";
			}
		}
		else if (temp == "back")
		{
			if (buff.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << buff.back() << "\n";
			}
		}
		count++;
	}
}