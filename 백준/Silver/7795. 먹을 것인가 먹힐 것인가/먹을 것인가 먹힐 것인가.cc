#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 0;
	cin >> t;
	int n, m = 0;
	while (t--)
	{
		cin >> n >> m;
		vector<int> arr1(n);
		vector<int> arr2(m);
		for (int i = 0; i < n; i++)
		{
			cin >> arr1[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> arr2[i];
		}
		sort(arr1.begin(), arr1.end());
		int answer = 0;
		for (int i = 0; i < m; i++)
		{
			int target_num = arr2[i];
			int idx = upper_bound(arr1.begin(), arr1.end(), target_num) - arr1.begin();
			answer += (n - idx);
		}
		cout << answer << '\n';
	}
	return 0;
}