#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	string s = "";
	set<string> tmp;
	while (n--)
	{
		cin >> s;
		sort(s.begin(), s.end());
		tmp.insert(s);
	}
	cout << tmp.size();
	return 0;
}