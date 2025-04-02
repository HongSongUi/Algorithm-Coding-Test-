#include <bits/stdc++.h>
using namespace std;
int length = 0;
int nx, ny = 0;
int tx, ty = 0;
vector<int> dx = { 1,-1,2,-2 };
vector<vector<int>> dy = { {2,-2} ,{2,-2} ,{1,-1},{1,-1} };

struct Point
{
    int x = 0;
    int y = 0;
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

bool IsVaild(int x, int y)
{
    return ((x >= 0 && x < length) && (y >= 0 && y < length));
}
void BFS()
{
    vector<vector<bool>> visited(length, vector<bool>(length, false));
    visited[ny][nx] = true;
    queue<pair<Point, int>> q;
    q.push(make_pair(Point(nx,ny),0));
    int answer = 0;
    while (!q.empty())
    {
        int cur_x = q.front().first.x;
        int cur_y = q.front().first.y;
        int d = q.front().second;
        if (cur_x == tx && cur_y == ty)
        {
            answer = d;
            break;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i][j];
                if (IsVaild(next_x, next_y) && !visited[next_y][next_x])
                {
                    visited[next_y][next_x] = true;
                    q.push(make_pair(Point(next_x, next_y), d + 1));
                }
            }
        }
    }
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;


    while (t--)
    {
        cin >> length;
        cin >> nx >> ny >> tx >> ty;
        BFS();
    }
    
    return 0;
}