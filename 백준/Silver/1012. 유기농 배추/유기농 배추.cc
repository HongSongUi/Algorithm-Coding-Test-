#include <bits/stdc++.h>
using namespace std;

void BFS(int x, int y, vector<vector<int>>& map, vector<vector<bool>>& visit, queue<pair<int, int>>& buff,int& count)
{
	buff.push(make_pair(x,y));
	visit[y][x] = true;
	
	vector<int> x_temp = { -1,1,0,0 };
	vector<int> y_temp = { 0,0,-1,1 };
	int near_x = 0;
	int near_y = 0;

	while (!buff.empty())
	{
		pair<int, int> cur = buff.front();
		buff.pop();
		for (int i = 0; i < 4; i++)
		{
			near_x = x_temp[i] + cur.first;
			near_y = y_temp[i] + cur.second;
			if (near_x <0 || near_x>map[0].size() - 1)
			{
				continue;
			}
			else if (near_y<0 || near_y>map.size() - 1)
			{
				continue;
			}
			if (map[near_y][near_x] == 0 || visit[near_y][near_x])
			{
				continue;
			}
			else if(map[near_y][near_x] ==1)
			{
				buff.push(make_pair(near_x, near_y));
				visit[near_y][near_x] = true;
			}
		}
	}
	count++;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	int x, y = 0;
	int num;
	cin >> n;



	int count = 0;
	int num1 = 0;
	int num2 = 0;

	while (n > 0)
	{
		cin >> x >> y >> num;
		vector<vector<int>> map(y, vector<int>(x, 0));
		vector<vector<bool>> visit(y, vector<bool>(x, false));
		queue<pair<int, int>> buff;
		for (int i = 0; i < num; i++)
		{
			cin >> num1 >> num2;
			map[num2][num1] = 1;
		}
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (map[i][j] == 1 && visit[i][j] == false)
				{
					BFS(j, i, map, visit, buff, count);
				}
			}
		}
		cout << count << "\n";
		count = 0;
		n--;
	}
}