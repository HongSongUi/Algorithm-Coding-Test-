#include <bits/stdc++.h>
#include <unordered_map>

using namespace std; 

int n = 0, m = 0;

vector<pair<int, int>> dir = { {1,0},{0,1} , {-1,0} ,{0,-1} }; // x,y r,b,l,t
vector<int> one_dir = { 0,1,2,3 };
vector<vector<int>> two_dir = { {0,2},{1,3} };
vector<vector<int>> three_dir = { {0,3},{0,1},{2,1},{2,3} };
vector<vector<int>> four_dir = { {0,2,3},{3,0,1},{0,1,2},{2,1,3} };
vector<vector<int>> five_dir = { {0,1,2,3} };

struct cctv
{
	int x;
	int y;
	int num;
	cctv()
	{
		x = 0;
		y = 0;
		num = 0;
	}
	cctv(int x, int y, int num)
	{
		this->num = num;
		this->x = x;
		this->y = y;
	}
};
vector<cctv> cctvs;
int answer = INT_MAX;
bool IsValid(int x, int y)
{
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}
void Vision(int x, int y, pair<int,int> dir,vector<vector<int>>& tmp)
{
	int cur_x = x;
	int cur_y = y;
	while (true)
	{
		int nx = cur_x + dir.first;
		int ny = cur_y + dir.second;
		if (!IsValid(nx, ny) || tmp[ny][nx] == 6) break;

		if (tmp[ny][nx] == 0)
		{
			tmp[ny][nx] = -1;
		}
		cur_x = nx;
		cur_y = ny;
	}
	return;
}
void BackTracking(vector<vector<int>>& graph, int idx)
{
	if (idx >= cctvs.size())
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (graph[i][j] == 0) cnt++;
			}
		}
		answer = min(answer, cnt);
		return;
	}
	
		int num = cctvs[idx].num;
		int x = cctvs[idx].x;
		int y = cctvs[idx].y;
		
		if (num == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				vector<vector<int>> tmp = graph;
				int t = one_dir[i];
				pair<int, int> d = dir[t];
				Vision(x, y, d, tmp);
				BackTracking(tmp, idx + 1);
			}
			
		}
		else if (num == 2)
		{
			for(int i = 0; i<2; i++)
			{
				vector<vector<int>> tmp = graph;
				for (int j = 0; j < 2; j++)
				{
					int t = two_dir[i][j];
					pair<int, int> d = dir[t];
					Vision(x, y, d, tmp);
				}
				BackTracking(tmp, idx + 1);
			}
		}
		else if (num == 3)
		{
			for (int i = 0; i < 4; i++)
			{
				vector<vector<int>> tmp = graph;
				for (int j = 0; j < 2; j++)
				{
					int t = three_dir[i][j];
					pair<int, int> d = dir[t];
					Vision(x, y, d, tmp);
				}
				BackTracking(tmp, idx + 1);
			}
		}
		else if (num == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				vector<vector<int>> tmp = graph;
				for (int j = 0; j < 3; j++)
				{
					int t = four_dir[i][j];
					pair<int, int> d = dir[t];
					Vision(x, y, d, tmp);
				}
				BackTracking(tmp, idx + 1);
			}
		}
		else
		{
			vector<vector<int>> tmp = graph;
			for (int i = 0; i < 4; i++)
			{
				int t = five_dir[0][i];
				pair<int, int> d = dir[t];
				Vision(x, y, d, tmp);
			}
			BackTracking(tmp, idx + 1);
		}


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	vector<vector<int>> graph(n, vector<int>(m));
	
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> graph[i][j];
			if (graph[i][j] > 0 && graph[i][j] < 6)
			{
				cctvs.emplace_back(cctv(j, i, graph[i][j]));
			}
		}
	}
	BackTracking(graph, 0);
	cout << answer;
	return 0;
}