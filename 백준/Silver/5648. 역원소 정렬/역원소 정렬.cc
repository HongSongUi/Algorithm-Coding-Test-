#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	vector<long long> arr;
	long long num = 0;
	int n = 0;
	cin >> n;
	string s = "";

	while (n--)
	{
		cin >> s;
		reverse(s.begin(), s.end());
		num = stoll(s);
		arr.emplace_back(num);
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << '\n';
	}
	return 0;
}