#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;

vector<vector<int>> graph;
vector<int> dx = { 1,-1,2,-2 };
vector<vector<int>> dy = { {2,-2} ,{2,-2} ,{1,-1},{1,-1} };

bool isVaild(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < n);
}

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    graph[y][x] = 0;
    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i][j];
                if (isVaild(next_x, next_y) && graph[next_y][next_x] == -1)
                {
                    graph[next_y][next_x] = graph[cur_y][cur_x] + 1;
                    q.push(make_pair(next_x, next_y));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n, vector<int>(n, -1));
    int start_x, start_y = 0;
    cin >> start_y >> start_x;
    BFS(start_x-1, start_y-1);
    
    int target_x, target_y = 0;
    
    for (int i = 0; i < m; i++)
    {
        cin >> target_y >> target_x;
        cout << graph[target_y - 1][target_x - 1] << ' ';
    }
    return 0;
}