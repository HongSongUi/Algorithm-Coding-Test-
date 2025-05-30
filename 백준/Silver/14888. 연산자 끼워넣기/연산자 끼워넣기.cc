#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<int> arr;
vector<int> oper(4);
vector<int> tmp;
vector<bool> visited;
int max_answer = INT_MIN;
int min_answer = INT_MAX;
void Func(int idx , int current)
{
	if (idx == n-1)
	{
		max_answer = max(max_answer, current);
		min_answer = min(min_answer, current);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (oper[i] >0)
		{
			oper[i]--;
			int next = current;
			if (i == 0)
			{
				next += arr[idx + 1];
			}
			else if (i == 1)
			{
				next -= arr[idx + 1];
			}
			else if (i == 2)
			{
				next *= arr[idx + 1];
			}
			else if (i == 3)
			{
				next /= arr[idx + 1];
			}
			Func(idx + 1,next);
			oper[i]++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	arr.resize(n);
	visited.resize(4);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}
	Func(0, arr[0]);
	cout << max_answer << '\n' << min_answer;
	return 0;
}