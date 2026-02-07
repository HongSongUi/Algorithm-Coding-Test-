#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, m = 0;
	cin >> n >> m;

	map<string, int> name_key;
	map<int, string> number_key;

	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		name_key[name] = i + 1;
		number_key[i + 1] = name;
	}
	string s;
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (s[0] >= '0' && s[0] <= '9')
		{
			int k = stoi(s);
			cout << number_key[k] << '\n';
		}
		else
		{
			cout << name_key[s] << '\n';
		}
	}
	return 0;
}
