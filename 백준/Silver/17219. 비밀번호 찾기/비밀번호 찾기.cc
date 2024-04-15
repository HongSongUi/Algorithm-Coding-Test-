#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int m = 0;
	cin >> n >> m;
	map<string, string> password;
	string site = "";
	string pw = "";
	string find = "";
	for (int i = 0; i < n; i++)
	{
		cin >> site >> pw;
		password.insert(make_pair(site, pw));
	}
	for (int i = 0; i < m; i++)
	{
		cin >> find;
		cout << password[find] << "\n";
	}
}