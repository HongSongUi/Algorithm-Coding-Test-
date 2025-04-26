#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;

	string s = "";
	while (t--)
	{
		cin >> s;
		list<char> lt = {};
		list<char>::iterator cursor = lt.begin();
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '<')
			{
				if (cursor != lt.begin())
				{
					cursor--;
				}
				
			}
			else if (s[i] == '>')
			{
				if (cursor != lt.end())
				{
					cursor++;
				}
				
			}
			else if (s[i] == '-')
			{
				if (cursor != lt.begin())
				{
					cursor = lt.erase(--cursor);				
				}
				
			}
			else
			{
				cursor = lt.insert(cursor, s[i]);
				cursor++;
			}
		}
		for (auto data : lt)
		{
			cout << data;
		}
		cout << '\n';
	}
	return 0;
}
