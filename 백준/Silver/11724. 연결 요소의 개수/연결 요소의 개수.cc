#include <bits/stdc++.h>
using namespace std;

void DFS(int point,vector<vector<int>>& buff, vector<bool>& visit)
{
	visit[point] = true;
	int num = 0;
	for (int i = 0; i < buff[point].size(); i++)
	{
		num = buff[point][i];
		if (visit[num] == false)
		{
			DFS(num, buff, visit);
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	cin >> N >> M;
	vector<vector<int>> buff(N + 1);
	vector<bool> visit(N + 1, false);
	int num1 = 0;
	int num2 = 0;
	int count = 0;
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		buff[num1].emplace_back(num2);
		buff[num2].emplace_back(num1);
	}
	for (int i = 1; i < visit.size(); i++)
	{
		if (visit[i] == false)
		{
			DFS(i, buff, visit);
			count++;
		}
	}
	cout << count;
}