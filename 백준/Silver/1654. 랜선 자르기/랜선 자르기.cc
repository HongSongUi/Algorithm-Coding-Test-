#include <bits/stdc++.h>
using namespace std;


void Search(long long start, long long end, long long& result, int n, vector<long long>& buff)
{
	if (start > end)
	{
		return;
	}
	long long mid = (start + end) / 2;
	int count = 0;
	for (int i = 0; i < buff.size(); i++)
	{
		count = count + (buff[i] / mid);
	}
	if (count >= n)
	{
		result = mid;
		start = mid + 1;
		Search(start, end, result, n, buff);
	}
	else
	{
		end = mid - 1;
		Search(start, end, result, n, buff);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int k = 0;
	int n = 0;
	cin >> k;
	cin >> n;
	vector<long long>buff(k);
	long long start = 1;
	long long end = 0;
	long long mid = 0;
	long long count = 0;
	long long result = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> buff[i];
		if (buff[i] >= end)
		{
			end = buff[i];
		}
	}
	Search(start, end, result, n, buff);
    cout << result;
}