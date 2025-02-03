#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<int> dx = { 1,0,1 };
vector<int> dy = { 0,1,1 };
vector<vector<bool>> visited;
vector<vector<int>> graph;
int answer = 0;

bool isVaild(int x, int y)
{
    return ((x >= 0 && x < n) && (y >= 0 && y < n));
}
void DFS(int x, int y, int dir)
{
    if (x == n - 1 && y == n - 1)
    {
        answer++;
        return;
    }
    visited[y][x] = true;
    for (int i = 0; i < 3; i++)
    {
        if (dir == 0 && i == 1)
        {
            continue;
        }
        else if (dir == 1 && i == 0)
        {
            continue;
        }
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if (isVaild(next_x, next_y))
        {
            if (i < 2)
            {
                if (graph[next_y][next_x] == 0 && visited[next_y][next_x] == false)
                {
                    DFS(next_x, next_y, i);
                    visited[next_y][next_x] = false;
                }
            }
            else
            {
                if (graph[next_y][next_x] == 0 && graph[next_y - 1][next_x] == 0 && graph[next_y][next_x - 1] == 0 && visited[next_y][next_x]==false)
                {
                    DFS(next_x, next_y, i);
                    visited[next_y][next_x] = false;
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n;
    graph.resize(n, vector<int>(n, 0));
    visited.resize(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    DFS(1, 0, 0);
    cout <<answer;
    return 0;
}