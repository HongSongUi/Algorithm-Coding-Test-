#include <bits/stdc++.h>
using namespace std;

int n, m;

bool FindNumber(int& depth)
{
	queue<pair<long long, int>> q;
	vector<bool> visited;
	visited.resize(m+1, false);
	q.push(make_pair(n, depth));
	visited[n] = true;
	while (!q.empty())
	{
		long long cur_num = q.front().first;
		long long cur_depth = q.front().second;
		q.pop();
		for (int i = 1; i <= 2; i++)
		{
			long long next_num = cur_num;
			if (i == 1)
			{
				next_num *= 10;
				next_num += 1;
			}
			else
			{
				next_num *= 2;
			}
			if (next_num == m)
			{
				depth = cur_depth + 1;
				return true;
			}
			else
			{
				if (next_num<m &&visited[next_num] == false)
				{
					q.push(make_pair(next_num, cur_depth + 1));
					visited[next_num] = true;
				}		
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	int depth = 1;
	
	bool check = FindNumber(depth);
	if (check)
	{
		cout << depth;
	}
	else
	{
		cout << "-1";
	}
}