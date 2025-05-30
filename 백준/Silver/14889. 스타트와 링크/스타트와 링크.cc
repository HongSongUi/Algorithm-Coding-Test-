#include <bits/stdc++.h>
using namespace std;
int limit;
int n = 0;
vector<bool> visited;
vector<vector<int>> arr;
int answer = INT_MAX;
void Calc()
{
	vector<int> a;
	vector<int> b;
	for (int i = 1; i < visited.size(); i++)
	{
		if (visited[i]) a.emplace_back(i);
		else b.emplace_back(i);
	}
	int num1 = 0;
	int num2 = 0;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			num1 += arr[a[i]-1][a[j]-1] + arr[a[j]-1][a[i]-1];
			num2 += arr[b[i]-1][b[j]-1] + arr[b[j]-1][b[i]-1];
		}
	}
	answer = min(answer, abs(num1 - num2));
}

void Func(int idx , int count)
{
	if (count == limit)
	{
		Calc();
		return;
	}
	for (int i = idx; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			Func(i + 1, count + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	arr.resize(n, vector<int>(n));
	visited.resize(n+1);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	limit = n / 2;

	Func(1, 0);
    cout << answer;
	return 0;
}