#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	int k = 0;
	cin >> n >> k;
	vector<long long> arr(n,0);

	cin >> arr[0];
	for (int i = 1; i < n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	sort(arr.rbegin(), arr.rend());

	long long answer = 0;
	for (int i = 0; i < k; i++)
	{
		answer += arr[i];
	}
	cout << answer;
	return 0;
}