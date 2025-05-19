#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	else if (a.length() == b.length())
	{
		int num1 = 0;
		int num2 = 0;
		for (int i = 0; i < a.length(); i++)
		{
			num1 = num1 + (a[i] - '0' >= 0 && a[i] - '0' <= 9 ? a[i] - '0' : 0);
			num2 = num2 + (b[i] - '0' >= 0 && b[i] - '0' <= 9 ? b[i] - '0' : 0);
		}
		if (num1 != num2)
		{
			return num1 < num2;
		}
	}
	return a < b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}