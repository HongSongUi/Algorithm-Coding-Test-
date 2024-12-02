#include <bits/stdc++.h>
using namespace std;

void FindParent(vector<vector<int>>& tree, vector<int>& parent_arr)
{
	vector<bool> visited(tree.size(), false);
	queue<int> q;
	q.push(1);
	visited[1] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < tree[cur].size(); i++)
		{
			int next_point = tree[cur][i];

			if (visited[next_point] == false)
			{
				parent_arr[next_point] = cur;
				q.push(next_point);
				visited[next_point] = true;
			}

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	vector<vector<int>> tree(n + 1);
	int parent = 0;
	int child = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> parent >> child;
		tree[parent].emplace_back(child);
		tree[child].emplace_back(parent);
	}
	vector<int> parent_arr(n + 1, 0);
	FindParent(tree, parent_arr);
	for (int i = 2; i < parent_arr.size(); i++)
	{
		cout << parent_arr[i] << '\n';
	}
}