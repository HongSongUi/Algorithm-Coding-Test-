#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	long long num = 0;
	long long sum = 0, tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		sum += num;
		tmp += num * num;
	}
	long long answer = (sum * sum - tmp) / 2;
	cout << answer ;

	return 0;
}