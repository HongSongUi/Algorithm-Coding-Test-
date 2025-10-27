#include <bits/stdc++.h>
using namespace std;
vector<int> dx = { -1,0,1,0 };
vector<int> dy = { 0,-1,0,1 };
int n = 0;
int m = 0;
struct Point
{
    int x;
    int y;
    int depth;
    Point(int x, int y, int d)
    {
        this->x = x;
        this->y = y;
        depth = d;
    }
};
bool IsValid(int x, int y)
{
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}

int BFS(vector<vector<int>>& graph)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<Point> q;
    visited[0][0] = true;
    q.push(Point(0,0,1));

    while (!q.empty())
    {
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        int cur_depth = q.front().depth;
        q.pop();

        if (cur_x == (m - 1) && cur_y == (n - 1))
        {
            return cur_depth;
        }

        for (int i = 0; i < 4; i++)
        {
            int next_x = cur_x + dx[i];
            int next_y = cur_y + dy[i];
            if (IsValid(next_x, next_y) && !visited[next_y][next_x]&& graph[next_y][next_x] != 0)
            {
                visited[next_y][next_x] = true;
                q.push(Point(next_x, next_y, cur_depth + 1));
            }
        }
    }
    return -1;
}


int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = BFS(maps);
    return answer;
}