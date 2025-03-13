#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string str = "";
	cin >> str;
	set<string> tmp;
	for (int i = 0; i < str.length(); i++)
	{
		string s = str.substr(i);
		tmp.insert(s);
	}

	for (auto data : tmp)
	{
		cout << data << '\n';
	}

	return 0;
}