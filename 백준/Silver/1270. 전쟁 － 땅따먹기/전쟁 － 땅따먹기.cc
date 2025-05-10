#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	int t = 0;
	while (n--)
	{
		cin >> t;
		vector<long long> arr(t);
		for (int i = 0; i < t; i++)
		{
			cin >> arr[i];
		}
		long long major = 0;
		long long count = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (count == 0)
			{
				major = arr[i];
			}
			if (major == arr[i])
			{
				count++;
			}
			else
			{
				count--;
			}
		}
		int half = t / 2;
		long long tmp = 0;
		for (int i = 0; i < arr.size(); i++)
		{
			if (major == arr[i])
			{
				tmp++;
			}
		}
		if (tmp > half)
		{
			cout << major << '\n';
		}
		else
		{
			cout << "SYJKGW" << '\n';
		}
	}
	return 0;
}