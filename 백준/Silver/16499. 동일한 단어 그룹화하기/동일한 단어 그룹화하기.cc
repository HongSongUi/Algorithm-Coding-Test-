#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	string s = "";
	map<string, int>tmp;
	
	while (n--)
	{
		cin >> s;
		sort(s.begin(), s.end());
		tmp[s]++;
	}
	cout << tmp.size();
	return 0;
}