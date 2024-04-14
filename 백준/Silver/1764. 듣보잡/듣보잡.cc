#include <bits/stdc++.h>
using namespace std;

bool Compare(string& a, string& b)
{
	return a < b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	cin >> n >> k;

	map<string, int> buff;
	vector<string> find;
	string name = "";
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		buff[name]++;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> name;
		buff[name]++;
		if (buff[name] == 2)
		{
			count++;
			find.emplace_back(name);
		}
	}
	sort(find.begin(), find.end(), Compare);
	cout << count << "\n";
	for (int i = 0; i < find.size(); i++)
	{
		cout << find[i]<<"\n";
	}
}