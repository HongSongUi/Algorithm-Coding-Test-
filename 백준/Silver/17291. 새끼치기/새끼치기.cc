#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	vector<int> arr(21,0);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	arr[4] = 7;

	for (int i = 5 ;i <= n; i++)
	{
		if (i % 2 == 0)
		{
			arr[i] = (arr[i - 1] * 2) - (arr[i - 4] + arr[i - 5]);
		}
		else
		{
			arr[i] = arr[i - 1] * 2;
		}
	}
	cout << arr[n];

	return 0;
}