#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> result;
vector<bool> visited;
set<vector<int>> temp;
void Combination(int depth)
{
	if (depth == m)
	{
		temp.insert(result);
		return;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			result.emplace_back(arr[i]);
			Combination(depth + 1);
			result.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.resize(n);
	visited.resize(n, false);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	Combination(0);

	for (auto it : temp)
	{
		for (int i = 0; i < it.size(); i++)
		{
			cout << it[i] << " ";
		}
		cout << '\n';
	}
	
}