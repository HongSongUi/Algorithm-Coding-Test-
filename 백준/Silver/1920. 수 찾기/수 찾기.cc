#include <bits/stdc++.h>
using namespace std;

bool BinarySearch(vector<int>& vec, int low, int high, int find_num)
{
	if (low > high)
	{
		return false;
	}
	int mid = (high + low) / 2;
	if (find_num == vec[mid])
	{
		return true;
	}
	if (find_num > vec[mid])
	{

		return BinarySearch(vec, mid + 1, high, find_num);
	}
	else
	{
		return BinarySearch(vec, low, mid - 1, find_num);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m = 0;
	cin >> n;
	vector<int> a_temp(n);
	int num = 0;
	int high = n-1;
	int low = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a_temp[i];
	}
	sort(a_temp.begin(), a_temp.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		if (BinarySearch(a_temp, low, high, num))
		{
			cout << 1 << "\n";
		}
		else
		{
			cout << 0 << "\n";
		}
	}
}