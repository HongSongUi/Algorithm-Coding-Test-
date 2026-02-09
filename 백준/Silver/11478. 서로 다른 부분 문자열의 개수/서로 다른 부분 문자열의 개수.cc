#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;




int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string s;	
	cin >> s;
	map<string, int> cnt;
	
	string tmp = "";
	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length(); j++)
		{
			tmp = s.substr(i, j);
			cnt[tmp]++;
		}
	}
	cout << cnt.size();
	return 0;
}
