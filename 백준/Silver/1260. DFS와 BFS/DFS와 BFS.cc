#include <bits/stdc++.h>
using namespace std;

void BFS(int start_point, vector<vector<int>>& buff)
{
	queue<int> bfs;
	vector<bool> visit(buff.size(), false);
	visit[start_point] = true;
	bfs.push(start_point);
	while (!bfs.empty())
	{
		int current = bfs.front();
		
		cout << current << " ";
		bfs.pop();
		for (int i = 0; i < buff[current].size(); i++)
		{
			int temp = buff[current][i];
			if (visit[temp] == false)
			{
				bfs.push(temp);
				visit[temp] = true;
			}
		}
	}
}
void DFS(int start_point,vector<vector<int>>& buff, vector<bool>& visit)
{
	visit[start_point] = true;
	cout << start_point << " ";
	for (int i = 0; i < buff[start_point].size(); i++)
	{
		int temp = buff[start_point][i];
		if (visit[temp] == false)
			DFS(buff[start_point][i], buff, visit);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int m = 0;
	int start_point = 0;
	cin >> n >> m >> start_point;
	vector<vector<int>> buff(n + 1);
	vector<bool> visit(n + 1, false);
	int num1 = 0;
	int num2 = 0;

	for (int i = 0; i < m; i++)
	{
		cin >> num1 >> num2;
		buff[num1].emplace_back(num2);
		buff[num2].emplace_back(num1);
	}
	for (int i = 0; i < buff.size(); i++)
	{
		sort(buff[i].begin(), buff[i].end());
	}
	DFS(start_point, buff, visit);
	cout << "\n";
	BFS(start_point, buff);
}