#include <bits/stdc++.h>
using namespace std;

void DFS(int num,int& count ,vector<vector<int>>& graph, vector<bool>& visit)
{
	visit[num] = true;
	for (int i = 0; i < graph[num].size(); i++)
	{
		int temp = graph[num][i];
		if (visit[temp] == false)
		{
			DFS(temp, count, graph, visit);
			count++;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int k = 0;
	cin >> n;
	cin >> k;
	int num1 = 0;
	int num2 = 0;
	vector<vector<int>> graph(n+1);
	vector<bool> visit(n+1);
	int count = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> num1 >> num2;
		graph[num1].emplace_back(num2);
		graph[num2].emplace_back(num1);
	}
	DFS(1,count, graph, visit);
	cout << count;
}