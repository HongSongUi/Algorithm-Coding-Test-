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
	string temp = "";
	stack<int> ps;
	bool vps = true;
	while (count < n)
	{
		cin >> temp;
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '(')
			{
				ps.push(0);
			}
			else if (temp[i] == ')')
			{
				if (ps.size() == 0)
				{
					vps = false;
					break;
				}
				else
				{
					ps.pop();
				}
			}
		}
		if (vps)
		{
			if (ps.size() == 0)
			{
				cout << "YES" << "\n";
			}
			else
				cout << "NO" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
		count++;
		vps = true;
		temp = "";
		while (!ps.empty()) ps.pop();
	}
}