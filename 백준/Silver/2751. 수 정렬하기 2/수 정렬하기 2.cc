#include <bits/stdc++.h>
using namespace std;
// 오름차순 정렬 -> 단순히 sort사용
// O(n log n)
int main()
{
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
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\n";
	}
	return 0;
}