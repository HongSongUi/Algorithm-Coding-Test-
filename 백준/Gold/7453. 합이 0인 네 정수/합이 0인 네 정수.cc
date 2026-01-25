#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c(n);
	vector<ll> d(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	vector<ll> ab;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ab.emplace_back(a[i] + b[j]);
		}
	}
	sort(ab.begin(), ab.end());
	ll result = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ll target = -(c[i] + d[j]);

			int low = lower_bound(ab.begin(), ab.end(), target) - ab.begin();
			int upper = upper_bound(ab.begin(), ab.end(), target) - ab.begin();
			result += upper - low;
		}
	}

	cout << result << '\n';
	return 0;
}