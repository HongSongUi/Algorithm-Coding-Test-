#include <bits/stdc++.h>
#include <unordered_map>

#define INF 20000001
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0; 
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}
	int left = 0;
	int right = n - 1;
	int maxSum = INT_MAX;
	int answer1 = 0;
	int answer2 = 0;
	while (left < right)
	{
		int s = vec[left] + vec[right];

		if (abs(s) < maxSum)
		{
			maxSum = abs(s);
			answer1 = vec[left];
			answer2 = vec[right];
		}
		if (s < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	cout << answer1 << ' ' << answer2;
	return 0;
}
