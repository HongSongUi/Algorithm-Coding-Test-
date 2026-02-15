#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	int answer = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		int money = vec[i];
		if (money > k) continue;

		answer += k / money;
		k = k % money;
	}
	cout << answer;
	return 0;
}
