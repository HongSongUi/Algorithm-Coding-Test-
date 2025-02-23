#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	long long num = 0;
	long long n = 0;
	int tCase = 1;
	int count = 1;
	
	long long answer = n;
	while (t--)
	{
		cin >> n;
		num = n;
		set<int> temp;
		if (n == 0)
		{
			cout << "Case #" << tCase << ": " << "INSOMNIA" << '\n';
			tCase++;
			continue;
		}
		while (temp.size() < 10)
		{
			n = num * count;
			answer = n;
			while (n > 0)
			{
				temp.insert(n % 10);
				n /= 10;
			}
			count++;
		}
		cout << "Case #" << tCase << ": " << answer << '\n';
		tCase++;
		count = 1;
		answer = 0;
	}
	return 0;
}