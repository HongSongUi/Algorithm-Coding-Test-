#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	string name = "";
	map<string, int> m;
	while (n--)
	{
		cin >> name;
		string tmp = name.substr(name.find('.')+1);
		m[tmp]++;
	}
	for (auto data : m)
	{
		cout << data.first << " " << data.second << '\n';
	}

	return 0;
}