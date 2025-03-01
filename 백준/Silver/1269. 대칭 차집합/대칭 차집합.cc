#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	map<int, int> tmp;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tmp[num]++;
	}
	int answer = n + m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		tmp[num]++;
		if (tmp[num] == 2)
		{
			answer -= 2;
		}
	}
	cout << answer;
	return 0;
}