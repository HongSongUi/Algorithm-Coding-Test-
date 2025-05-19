#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<long long> arr(n);
	string s = "";
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		reverse(s.begin(), s.end());
		arr[i] = (stoll(s));
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}