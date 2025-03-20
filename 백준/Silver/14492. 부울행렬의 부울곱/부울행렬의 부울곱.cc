#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<vector<bool>> a(n, vector<bool>(n, 0));
	vector<vector<bool>> b(n, vector<bool>(n, 0));
	bool tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0 ;j < n; j++)
		{
			cin >> tmp;
			a[i][j] = tmp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			b[i][j] = tmp;
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (k == 0)
				{
					tmp = a[i][k] && b[k][j];
				}
				else
				{
					tmp = a[i][k] && b[k][j] || tmp;
				}
			}
			if (tmp)
			{
				answer++;
			}
		}
	}
	cout << answer;
	return 0;
}