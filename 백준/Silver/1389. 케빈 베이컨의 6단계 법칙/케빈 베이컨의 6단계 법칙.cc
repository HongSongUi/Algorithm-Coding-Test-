#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	int M = 0;
	cin >> N >> M;
	int num1 = 0;
	int num2 = 0;
	vector<vector<int>> graph(N+1, vector<int>(N+1));
	vector<int> sum(N+1,0);
	int max = 9999999;
	for (int i = 1; i < N+1; i++)
	{
		for (int j = 1; j < N+1; j++)
		{
			graph[i][j] = max;
		}
	}
	for (int i = 0; i < M;i++)
	{
		cin >> num1 >> num2;
		graph[num1][num2] = 1;
		graph[num2][num1] = 1;
	}
	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	for (int i = 1; i < graph.size(); i++)
	{
		for (int j = 1; j < graph[i].size(); j++)
		{
			if (i != j)
			{
				sum[i] += graph[i][j];
			}
		}
	}
	int result = 0;
	for (int i = 1; i < sum.size(); i++)
	{
		if (sum[i] < max)
		{
			max = sum[i];
			result = i;
		}
	}
	cout << result;
}