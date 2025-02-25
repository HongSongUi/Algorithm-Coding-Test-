#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int midIdx = n / 2;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += abs(arr[midIdx] - arr[i]);
	}
	int answer = arr[midIdx];
	int temp = 0;
	for (int i = midIdx - 1; i >= 0; i--)
	{
		temp = 0;
		for (int j = 0; j < n; j++)
		{
			temp += abs(arr[i] - arr[j]);
		}
		if (temp <= sum)
		{
			answer = arr[i];
			sum = temp;
		}
		else if (temp > sum)
		{
			break;
		}
	}
	cout << answer;
	return 0;
}