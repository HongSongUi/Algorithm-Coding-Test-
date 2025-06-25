#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0 ,  t = 0;
	cin >> n >> t;
	vector<int> arr(n+1);
	vector<int> sum(n+1,0);
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}
	int s = 0;
	int e = 0;
	while (t--)
	{
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << '\n';
	}
	return 0;
}