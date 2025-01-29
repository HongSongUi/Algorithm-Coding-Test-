#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;

int n, m;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,1,0,-1, };

vector<pair<int,int>> virus;
int maxCount = -1;
bool CheckPoint(int x, int y)
{
    if ((x >= 0 && x < m) && (y >= 0 && y < n))
    {
        return true;
    }
    return false;
}
void BFS()
{
    vector<vector<int>> temp = graph;
    int zeroCount = 0;
    queue<pair<int,int>>q;
    for (int i = 0; i < virus.size(); i++)
    {
        q.push(virus[i]);
    }
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (CheckPoint(next_x, next_y) && temp[next_y][next_x] == 0)
            {
                temp[next_y][next_x] = 2;
                q.push(make_pair( next_x,next_y ));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 0)
            {
                zeroCount++;
            }
        }
    }
    maxCount = max(maxCount, zeroCount);
}
void Wall(int count)
{
    if (count == 3)
    {
        BFS();
        return;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = 1;
                Wall(count + 1);
                graph[i][j] = 0;
            }
        }
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    graph.resize(n, vector<int>(m, 0));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 2)
            {
                virus.emplace_back(make_pair( j,i ));
            }
        }
    }
    int answer = 0;

    Wall(0);
    cout << maxCount;
    return 0;
}