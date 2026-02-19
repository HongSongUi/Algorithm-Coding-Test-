#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str = "";
	cin >> str;

	int answer = 0;
	
	bool flag = false;
	string tmp = "";
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp += str[i];
		}
		else 
		{
			int d = (flag == false) ? 1 : -1;
			int n = stoi(tmp);
			n *= d;
			answer += n;
			tmp = "";
		}
		if (str[i] == '-') flag = true;
	}
	int d = (flag == false) ? 1 : -1;
	int n = stoi(tmp);
	n *= d;
	answer += n;
	cout << answer;
	return 0;
}
