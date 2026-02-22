#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int n = 0, m = 0;
vector<pair<int, int>> dir = { {-1,0} ,{-1,-1},{0,-1} ,{1,-1},{1,0} ,{1,1},{0,1},{-1,1} }; // x y
vector<vector<int>> graph;
vector<vector<bool>> cloud;
queue<pair<int, int>> cloud_q;
queue<pair<int, int>> wq;
bool IsValid(int x, int y)
{
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

void MoveCloud(int d, int s)
{
	vector<vector<bool>> nCloud(n, vector<bool>(n, false));
	queue<pair<int, int>>t;
	while (!cloud_q.empty())
	{
		int cur_x = cloud_q.front().first;
		int cur_y = cloud_q.front().second;
		cloud_q.pop();
		int dx = dir[d].first;
		int dy = dir[d].second;
		
		int nx = cur_x + (dx * s);
		int ny = cur_y + (dy * s);

		nx %= n;
		ny %= n;
		if (nx < 0) nx += n;
		if (ny < 0) ny += n;
		graph[ny][nx]++;
		t.push(make_pair(nx, ny));
		nCloud[ny][nx] = true;
	}
	cloud = nCloud;
	wq = t;
}
void CopyWater()
{
	while (!wq.empty())
	{
		int cur_x = wq.front().first;
		int cur_y = wq.front().second;
		wq.pop();
		int cnt = 0;
		for (int i = 1; i < 8; i+=2)
		{
			int nx = cur_x + dir[i].first;
			int ny = cur_y + dir[i].second;

			if (IsValid(nx, ny) && graph[ny][nx] > 0)
			{
				cnt++;
			}
		}
		graph[cur_y][cur_x] += cnt;
	}
}
void MakeCloud()
{
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			flag = false;
			if (graph[i][j] >= 2&& !cloud[i][j])
			{
				graph[i][j] -= 2;
				cloud_q.push(make_pair(j, i));

			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n>>m;
	graph.resize(n, vector<int>(n));
	cloud.resize(n, vector<bool>(n, false));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}
	queue<pair<int, int>> q; // d s
	int d = 0, s = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> d >> s;
		q.push(make_pair(d, s));
	}
	cloud_q.push(make_pair(0, n - 1));
	cloud_q.push(make_pair(1, n - 1));
	cloud_q.push(make_pair(0, n - 2));
	cloud_q.push(make_pair(1, n - 2));
	while (!q.empty())
	{
		int cur_d = q.front().first-1;
		int cur_s = q.front().second;
		q.pop();
		MoveCloud(cur_d, cur_s);
		CopyWater();
		MakeCloud();
	}
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += graph[i][j];
		}
	}
	cout << answer;
	return 0;
}
