#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	map<int, int> cnt;
	int left = 0;
	int right = 0;
	int cur_len = 0;
	int max_len = 0;
	while (true)
	{
		if (right == vec.size() )break;
		if (cnt[vec[right]] <= k)
		{
			cnt[vec[right]]++;
			while (cnt[vec[right]] > k)
			{
				cnt[vec[left]]--;
				left++;
			}
			right++;
		}
		cur_len = right - left;
		max_len = max(max_len, cur_len);
	}
	cout << max_len;
	return 0;
}
