#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> graph;

bool IsVaild(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < n);
}

bool BFS()
{
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    visited[0][0] = true;
    bool tmp = false;
    q.push(make_pair(0, 0));
    while(!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if (cur_x == n - 1 && cur_y == n - 1)
        {
            tmp = true;
        }
        int next_x = cur_x + graph[cur_y][cur_x];
        int next_y = cur_y;
        if (IsVaild(next_x, next_y) && !visited[next_y][next_x])
        {
            visited[next_y][next_x] = true;
            q.push(make_pair(next_x, next_y));
        }
        next_x = cur_x;
        next_y = cur_y + graph[cur_y][cur_x];
        if (IsVaild(next_x, next_y) && !visited[next_y][next_x])
        {
            visited[next_y][next_x] = true;
            q.push(make_pair(next_x, next_y));
        }
    }
    return tmp;
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
}