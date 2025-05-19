#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> arr(10001,0);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}
	for (int i = 0; i < 10001; i++)
	{
		if (arr[i] == 0) continue;
		while (arr[i] > 0)
		{
			cout << i << '\n';
			arr[i]--;
		}
	}
	return 0;
}