#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int rank = 0;
	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
    vector<int> arr(n);
	int per = round(n * 0.15);
	float ave = 0.f;
	int result = 0;
	int start = per;
	int end = n - per;
	
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	for (int i = start; i < end; i++)
	{
		ave += arr[i];
	}
	ave = ave / (end - start);
	result = round(ave);
	cout << result;
}