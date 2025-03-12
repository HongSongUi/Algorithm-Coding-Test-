#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	int zero_count = n;
	int num = 1;
	int count = -1;
	int index = -1;
	while (zero_count > 0)
	{
		while (true)
		{
			index++;
			index %= n;
			if (arr[index] == 0)
			{
				count++;
			}
			if (count == num)
			{
				arr[index] = num;
				break;
			}
		}
		num++;
		count = -1;
		zero_count--;
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}