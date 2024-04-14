#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	string temp = "";
	int number = 0;
	cin >> n;
	vector<bool> buff(20);
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		if (temp == "add")
		{
			cin >> number;
			if (buff[number] == true)
			{
				continue;
			}
			buff[number] = true;
		}
		else if (temp == "remove")
		{
			cin >> number;
			if (buff[number] == false)
			{
				continue;
			}
			buff[number] = false;
		}
		else if (temp == "check")
		{
			cin >> number;
			if (buff[number] == false)
			{
				cout << 0<<"\n";
			}
			else
			{
				cout << 1<<"\n";
			}
		}
		else if (temp == "toggle")
		{
			cin >> number;
			if (buff[number]==true)
			{
				buff[number] = false;
			}
			else
			{
				buff[number] = true;
			}
		}
		else if (temp == "all")
		{
			buff.assign(20, true);
		}
		else if (temp == "empty")
		{
			buff.assign(20, false);
		}
	}
}