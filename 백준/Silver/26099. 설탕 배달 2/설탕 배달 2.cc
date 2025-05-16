#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n = 0;
	cin >> n;
	long long count = 0;
	while (n % 5 != 0)
	{
		n -= 3;
		count++;
	}
	if (n < 0)
	{
		cout << -1;
		return 0;
	}
	count += n / 5;
	cout << count;
	return 0;
}