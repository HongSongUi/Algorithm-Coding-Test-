#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t = 0;
	cin >> t;
	while (t--)
	{
		int n = 0;
		int m = 0;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < m; i++)
		{
			int target = b[i];
			int idx = upper_bound(a.begin(), a.end(), target) - a.begin();
			cnt += (n - idx);

		}
		cout << cnt << '\n';
	}

	return 0;
}
