#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	string s = "";
	int k = 0;
	int m = 0;
	int evo_count = 0;
	string name = "";
	int max_count = 0;
	while (n--)
	{
		cin >> s;
		cin >> k >> m;
		int count = 0;
		while (k <= m)
		{
			m -= k;
			count++;
			m += 2;
			evo_count++;
		}
		if (max_count < count)
		{
			name = s;
			max_count = count;
		}
	}
	cout << evo_count << '\n' << name;
	return 0;
}