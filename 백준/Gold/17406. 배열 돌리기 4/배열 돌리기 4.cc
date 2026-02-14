#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct rot
{
	int r = 0;
	int c = 0;
	int s = 0;
};

int n = 0;
int m = 0;
int k = 0;

vector<vector<int>> vec;
vector<rot> opers;
vector<bool> visited;
vector<rot> tmp;
int answer = INT_MAX;

void Calc()
{
	vector<vector<int>> bf = vec;
	vector<vector<int>> rotate_vec = bf;
	for (int i = 0; i < tmp.size(); i++)
	{
		int r = tmp[i].r;
		int c = tmp[i].c;
		int s = tmp[i].s;
		
		int sx = c - s - 1;
		int sy = r - s - 1;
		int ex = c + s - 1;
		int ey = r + s - 1;

		while (true)
		{
			if (sx == ex && sy == ey) break;

			for (int i = sx; i < ex; i++)
			{
				rotate_vec[sy][i + 1] = bf[sy][i];
			}
			for (int i = sy; i < ey; i++)
			{
				rotate_vec[i + 1][ex] = bf[i][ex];
			}
			for (int i = ex; i > sx; i--)
			{
				rotate_vec[ey][i - 1] = bf[ey][i];
			}
			for (int i = ey; i > sy; i--)
			{
				rotate_vec[i - 1][sx] = bf[i][sx];
			}
			sx++;
			sy++;
			ex--;
			ey--;
			int a = 0;
			bf = rotate_vec;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int val = 0;
		for (int j = 0; j < m; j++)
		{
			val += rotate_vec[i][j];
		}
		answer = min(val, answer);
	}
	return;
}
void Choose()
{
	if (tmp.size() == k)
	{
		
		Calc();
		return;
	}

	for (int i = 0; i < opers.size(); i++)
	{
		if (!visited[i])
		{
			tmp.emplace_back(opers[i]);
			visited[i] = true;
			Choose();
			tmp.pop_back();
			visited[i] = false;
		}
	}


}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	vec.resize(n, vector<int>(m));
	opers.resize(k);
	visited.resize(k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> vec[i][j];
		}
	}
	for (int i = 0; i < k; i++)
	{
		cin >> opers[i].r >> opers[i].c >> opers[i].s;
	}
	Choose();
	cout << answer;
	return 0;
}
