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
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int answer = 0;
		for (int i = 0; i < m; i++)
		{
			int tmp = b[i];
			int idx = upper_bound(a.begin(), a.end(), tmp) - a.begin();
			int cnt = n - idx;
			answer += cnt;
		}
		cout << answer << '\n';
	}
	return 0;
}
