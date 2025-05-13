#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
vector<int> tmp;
int n;
void Func()
{
	if (tmp.size() == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << tmp[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			tmp.emplace_back(i);
			Func();
			visited[i] = false;
			tmp.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	visited.resize(n + 1, false);
	Func();
	return 0;
}