#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;
	string str;
	int answer = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		vector<int> zero(m, 0);
		zero[0] = (str[0] == '1') ? 0 : 1;
		for (int j = 1; j < str.length(); j++)
		{
			if (str[j] == '1')
			{
				zero[j] = 0;
			}
			else
			{
				zero[j] = zero[j - 1] + 1;
			}
		}
		for (int j = 0; j < m; j++)
		{
			if (zero[j] >= k)
			{
				answer++;
			}
		}
	}

	cout << answer;
	return 0;
}