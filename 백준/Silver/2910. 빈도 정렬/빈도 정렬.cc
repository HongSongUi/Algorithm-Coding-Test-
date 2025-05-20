#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<int, int> freq;
unordered_map<int, int> nIndex;
bool cmp(int& a, int& b)
{
	if (freq[a] == freq[b]) return nIndex[a] < nIndex[b];
	return freq[a] > freq[b];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0, c = 0;
	cin >> n >> c;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (freq[arr[i]] == 0)
		{
			nIndex[arr[i]] = i;
		}
		freq[arr[i]]++;
	}
	sort(arr.begin(), arr.end(), cmp);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}