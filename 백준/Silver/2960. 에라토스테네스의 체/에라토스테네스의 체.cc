#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<bool> prime(n + 1, true);
	prime[0] = false;
	prime[1] = false;
	int count = 0;
	int answer = 0;
	vector<int> temp;
	for (int i = 2; i <= n; i++)
	{
		if (prime[i])
		{
			prime[i] = false;
			temp.emplace_back(i);
			for (int j = i * i; j <= n; j += i)
			{
				if (prime[j])
				{
					prime[j] = false;
					temp.emplace_back(j);
				}
			}
		}
	}
	cout << temp[k - 1];
	return 0;
}