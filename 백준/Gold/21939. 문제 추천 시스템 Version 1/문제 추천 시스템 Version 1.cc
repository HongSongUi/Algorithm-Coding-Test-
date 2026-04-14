#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	multiset<pair<int, int>> p_set;
	unordered_map<int, int> p2l;

	int n = 0, m = 0;
	cin >> n;

	int p, l;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> l;

		p_set.insert(make_pair(l, p));
		p2l.insert(make_pair(p, l));
	}
	cin >> m;
	string s = "";
	int x = 0;
	while (m>0)
	{
		cin >> s;
		if (s == "add")
		{
			cin >> p >> l;
			p_set.insert(make_pair(l, p));
			p2l.insert(make_pair(p, l));
		}
		else if (s == "recommend")
		{
			cin >> x;
			if (x == 1)
			{
				cout << prev(p_set.end())->second << '\n';
			}
			else if (x == -1)
			{
				cout << p_set.begin()->second << '\n';
			}
		}
		else if (s == "solved")
		{
			cin >> p;
			auto it = p2l.find(p);
			p_set.erase({ it->second, p });
			p2l.erase(it);
		}

		m--;
	}
	
	return 0;
}