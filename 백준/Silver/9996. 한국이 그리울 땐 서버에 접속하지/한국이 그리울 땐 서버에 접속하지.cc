#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	string pattern = "";
	cin >> pattern;
	int index = pattern.find("*");
	string fPattern = pattern.substr(0, index);
	string lPattern = pattern.substr(index + 1);
	while (n--)
	{
		string temp;
		cin >> temp;
		if (temp.size() < fPattern.size() + lPattern.size())
		{
			cout << "NE" << '\n';
			continue;
		}
		if (temp.substr(0, fPattern.size()) == fPattern && temp.substr(temp.size() - lPattern.size()) == lPattern)
		{
			cout << "DA";
		}
		else
		{
			cout << "NE";
		}
		cout << '\n';
	}
	return 0;
}