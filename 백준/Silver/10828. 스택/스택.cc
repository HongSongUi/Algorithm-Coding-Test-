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
	stack<int> buff;
	while (count < n)
	{
		cin >> temp;
		if (temp == "push")
		{
			cin >> num;
			buff.push(num);
		}
		else if (temp == "pop")
		{
			if (buff.size() == 0)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << buff.top() << "\n";
				buff.pop();
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
		else if (temp == "top")
		{
			if (buff.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << buff.top() << "\n";
			}
		}
		count++;
	}
}