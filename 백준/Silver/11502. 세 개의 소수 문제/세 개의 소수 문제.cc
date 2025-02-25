#include <bits/stdc++.h>
using namespace std;
vector<bool> isPrime(1001, true);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i <= 1000; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j <= 1000; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	int t = 0;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool isFind = false;
		for (int i = 2; i <= n; i++)
		{
			if (isPrime[i] == false) continue;
			for (int j = 2; j <= n; j++)
			{
				if (isPrime[j] == false) continue;
				for (int k = 2; k <= n; k++)
				{
					if (isPrime[k] == false) continue;
					
					if (i + j + k == n)
					{
						isFind = true;
						cout << i << " " << j << " " << k;
						break;
					}
				}
				if (isFind) break;
			}
			if (isFind) break;
		}
		if (isFind == false)
		{
			cout << 0;
		}
		cout << '\n';
	}
	return 0;
}