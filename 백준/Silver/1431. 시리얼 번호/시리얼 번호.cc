#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool cmp(string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	else if (a.length() == b.length())
	{
		int a_num = 0;
		int b_num = 0;
		for (int i = 0; i < a.length(); i++)
		{
			int tmp1 = a[i] - '0';
			int tmp2 = b[i] - '0';
			if (tmp1 >= 0 && tmp1 <= 9)
			{
				a_num += tmp1;
			}
			if (tmp2 >= 0 && tmp2 <= 9)
			{
				b_num += tmp2;
			}
		}
		if (a_num != b_num)
		{
			return a_num < b_num;
		}
	}
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<string> vec(n);
	char t = 'a';
	int a = t - '0';
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << '\n';
	}
	return 0;
}
