#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> graph;


bool isVaild(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < n);
}

bool BFS()
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[0][0] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if (cur_x == n - 1 && cur_y == n - 1)
        {
            return true;
        }
        
        int next_x = 0;
        int next_y = 0;
        next_x = cur_x + graph[cur_y][cur_x];
        next_y = cur_y;
        if (isVaild(next_x, next_y) && !visited[next_y][next_x])
        {
            visited[next_y][next_x] = true;
            q.push(make_pair(next_x, next_y));
        }
        next_x = cur_x;
        next_y = cur_y + graph[cur_y][cur_x];
        if (isVaild(next_x, next_y) && !visited[next_y][next_x])
        {
            visited[next_y][next_x] = true;
            q.push(make_pair(next_x, next_y));
        }   
    }

    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> n;
    graph.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    if (BFS())
    {
        cout << "HaruHaru";
    }
    else
    {
        cout << "Hing";
    }
    return 0;
}