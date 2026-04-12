#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		int k = 0;
		cin >> k;
		multiset<int> tmp;
		string s = "";
		int num = 0;
		while (k>0)
		{
			cin >> s;
			if (s == "I")
			{
				cin >> num;
				tmp.insert(num);
			}
			else if (s == "D")
			{
				if (tmp.empty()) continue;
				cin >> num;
				if (num == 1)
				{
					tmp.erase(--tmp.end());
				}
				else if (num == -1)
				{
					tmp.erase(tmp.begin());
				}
			}
			k--;
		}
		if (tmp.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << *--tmp.end() << ' ' << *tmp.begin() << '\n';
;		}
	}

	return 0;
}