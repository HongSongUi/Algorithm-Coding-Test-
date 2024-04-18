#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	cin >> n >> k;
	int start = 0;
	int end = 0;
	long long result = 0;
	vector<int> buff(n + 1, 0);
	vector<long long> sum(n + 1, 0);
	for (int i = 1; i < n + 1; i++)
	{
		cin >> buff[i];
		sum[i] = sum[i - 1] + buff[i];
	}
	while (k > 0)
	{
		cin >> start >> end;
		result = sum[end] - sum[start - 1];
		cout << result << "\n";
        k--;
	}
}