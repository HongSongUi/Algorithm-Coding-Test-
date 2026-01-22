#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<int> vec(10001);
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec[tmp]++;
	}
	for (int i = 1; i < 10001; i++)
	{
		if (vec[i] == 0) continue;
		for (int j = 0; j < vec[i]; j++)
		{
			cout << i << '\n';
		}
	}
	return 0;
}
