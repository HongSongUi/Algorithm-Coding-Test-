#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector <long long> vec(n);

	string tmp = "";
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		long long ll = stoll(tmp);
		vec[i] = ll;
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << '\n';
	}
	return 0;
}
