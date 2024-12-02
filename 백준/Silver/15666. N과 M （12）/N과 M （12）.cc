#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;
vector<int> start_arr;

vector<int> result;
set<vector<int>> temp;
void Combination(int depth, int start)
{
	if (depth == m)
	{
		temp.insert(result);
		return;
	}
	for (int i = start; i < arr.size(); i++)
	{
		result.emplace_back(arr[i]);
		Combination(depth + 1, i);
		result.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	Combination(0,0);

	for (auto it : temp)
	{
		for (int i = 0; i < it.size(); i++)
		{
			cout << it[i] << " ";
		}
		cout << '\n';
	}
}