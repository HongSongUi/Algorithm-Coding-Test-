#include <bits/stdc++.h>
using namespace std;

bool find_road(vector<vector<int>>& temp, int start, int end)
{
	vector<bool> visit(temp.size(), false);
	queue<int> check;
	check.push(start);
	bool have = false;
	while (check.size() != 0)
	{
		int cur = check.front();
		check.pop();
		for (int i = 0; i < temp[cur].size(); i++)
		{
			int num = temp[cur][i];
			if (num == end)
			{
				return true;
			}
			if (visit[num] == false)
			{
				check.push(num);
				visit[num] = true;
			}
		
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n, 0));
	vector<vector<int>> temp(n+1);
	queue<int> check;
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> num;
			if (num == 1)
			{
				graph[i][j] = num;
				temp[i+1].push_back(j+1);
			}
		}
	}
	int start = 0;
	int end = 0;
	for (int i = 0; i < n; i++)
	{
		start = i + 1;
		for (int j = 0; j < n; j++)
		{
			end = j + 1;
			
			if (find_road(temp,  start, end))
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}
}