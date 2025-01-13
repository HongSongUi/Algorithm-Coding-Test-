#include <bits/stdc++.h>
using namespace std;
int n, m;

struct Point
{
    int x = 0;
    int y = 0;
};
bool CheckRange(int x, int y)
{
    if ((x >= 0 && x < m) && (y >= 0 && y < n))
    {
        return true;
    }
    return false;
}

int BFS(vector<vector<int>>& graph)
{
    int start_x = 0;
    int start_y = 0;
    int end_x = graph[0].size() - 1;
    int end_y = graph.size() - 1;
    vector<vector<vector<bool>>> visited(graph.size(), vector<vector<bool>>(graph[0].size(), vector<bool>(2, false)));
    queue<pair<pair<Point, int>,int>> q;
    int d = -1;
    q.push(make_pair(make_pair(Point{ start_x,start_y }, 0), 0));
    vector<int> x = { -1,0,1,0 };
    vector<int> y = { 0,-1,0,1 };
    visited[start_y][start_x][0] = true;
    while (!q.empty())
    {
        int cur_x = q.front().first.first.x;
        int cur_y = q.front().first.first.y;
       
        int cur_depth = q.front().first.second;
        int break_count = q.front().second;
        if (cur_x == end_x && cur_y == end_y)
        {
            d = cur_depth;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + x[i];
            int next_y = cur_y + y[i];
            
            if (CheckRange(next_x, next_y))
            {
                Point p;
                p.x = next_x;
                p.y = next_y;
                if (graph[next_y][next_x] == 0 && visited[next_y][next_x][break_count] == false)
                {
                    visited[next_y][next_x][break_count] = true;
                    q.push(make_pair(make_pair(p, cur_depth + 1), break_count));
                }
                else if (graph[next_y][next_x] == 1 && break_count == 0)
                {
                    if (visited[next_y][next_x][1] == false)
                    {
                        visited[next_y][next_x][1] = true;
                        q.push(make_pair(make_pair(p, cur_depth + 1), 1));
                    }
                }

            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    string s = "";
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            int num = s[j] - '0';
            graph[i][j] = num;
        }
    }
    int answer = BFS(graph);
    if (answer == -1)
    {
        cout << answer;
    }
    else
    {
        cout << answer + 1;
    }
    return 0;
}