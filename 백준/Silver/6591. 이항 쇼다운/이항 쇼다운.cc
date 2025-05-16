#include <bits/stdc++.h>
using namespace std;

long long comb(long long n, long long k) 
{
	if (k > n - k) k = n - k; 
	long long ret = 1;
	for (long long i = 1; i <= k; ++i) 
	{
		ret = ret * (n - i + 1);
		ret /= i;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n = 0, k = 0;
	while (true)
	{
		cin >> n >> k;
		if (n == 0 && k == 0) break;
		cout << comb(n, k) << '\n';
	}
	return 0;
}