#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m = 0;
	int num = 0;
	cin >> n;
	map<int,int> buff;
	vector<int> arr;
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		buff[num]++;		
	}
	for (auto iter : buff)
	{
		temp.emplace_back(iter.first);
	}
	cin >> m;
	arr.resize(m);
	for (int i = 0; i < m; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < m; i++)
	{
		if (binary_search(temp.begin(), temp.end(), arr[i]))
		{
			cout << buff[arr[i]] << " ";
		}
		else
		{
			cout << 0 << " ";
		}
	}
}