#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> arr(n);
	map<int, int> mode_map;
	int ave = 0;
	double temp = 0;
	int mid = 0;
	int range = 0;
	int num = 0;
	int mod = 0;
	vector<int> buff;
	int max = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[i] = num;
		mode_map[num]++;
		temp += num;
	}
	temp /= n;
	ave = round(temp);
	sort(arr.begin(), arr.end());
	mid = (n - 1) / 2;
	mid = arr[mid];

	for (auto iter : mode_map)
	{
		if (iter.second >= max)
		{
			max = iter.second;
		}
	}
	for (auto iter : mode_map)
	{
		if (iter.second == max)
		{
			buff.emplace_back(iter.first);
		}
	}
	mod = buff[0];
	if (buff.size() > 1)
	{
		sort(buff.begin(), buff.end());
		mod = buff[1];
	}	
	range = arr[n - 1] - arr[0];
	cout << ave << "\n" << mid << "\n" << mod << "\n" << range;
}