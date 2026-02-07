#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;


	map<string, bool,greater<string>> enter_log;
	string name = "";
	string s = "";
	bool flag;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> s;
		flag = (s == "enter") ? true : false;
		enter_log[name] = flag;
	}

	for (auto data : enter_log)
	{
		if (data.second)
		{
			cout << data.first << '\n';
		}
	}
	return 0;
}
