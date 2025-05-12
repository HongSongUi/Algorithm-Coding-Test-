#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, m = 0;
	cin >> n >> m;
	int p = 0;
	int l = 0;
	vector<int> arr;
	while (n--)
	{
		cin >> p >> l;
		vector<int> subjects(p);
		for (int i = 0; i < p; i++)
		{
			cin >> subjects[i];
		}
		sort(subjects.begin(), subjects.end(),greater<int>());
		int num = 1;
		if (subjects.size() >= l)
		{
			num = subjects[l - 1];
		}
		arr.emplace_back(num);

	}
	sort(arr.begin(), arr.end());
	int answer = -1;
	for (int i = 0; i < arr.size(); i++)
	{
		if (m - arr[i] < 0)
		{
			answer = i;
			break;
		}
		m -= arr[i];
	}
	if (m >= 0 && answer==-1)
	{
		answer = arr.size();
	}
	cout << answer;
	return 0;
}