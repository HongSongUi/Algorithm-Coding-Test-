#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0, k = 0;
	cin >> n >> k;
	vector<int>vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int right = 0;
	int left = 0;
	int max_len = 0;
	int cur_len = 0;
	int cnt = 0;
	while (true)
	{
		if (cnt <= k)
		{
			if (right == vec.size()) break;

			if (vec[right] % 2 != 0)
			{
				cnt++;
			}
			right++;
		}
		
			while (cnt > k)
			{
				if (vec[left] % 2 != 0) cnt--;
				left++;
			}
		
		cur_len = (right - left - cnt);
		max_len = max(max_len, cur_len);
	}
	cout << max_len;
	return 0;
}
