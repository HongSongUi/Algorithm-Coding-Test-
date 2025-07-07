#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<vector<int>> rooms;
struct CCTV
{
    int num = 0;
    int x = 0;
    int y = 0;
    int dir = 0;
    CCTV()
    {}
    CCTV(int y, int x, int d,int n )
    {
        this->y = y;
        this->x = x;
        dir = d;
        num = n;
    }
};
vector<CCTV> cctvs;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
vector<vector<int>> cctvDir[6];

// 초기화 함수
void Init() 
{
    cctvDir[1] = { {0}, {1}, {2}, {3} };                   // Type 1
    cctvDir[2] = { {0, 2}, {1, 3} };                        // Type 2
    cctvDir[3] = { {0, 1}, {1, 2}, {2, 3}, {3, 0} };        // Type 3
    cctvDir[4] = { {0, 1, 2}, {1, 2, 3}, {2, 3, 0}, {3, 0, 1} }; // Type 4
    cctvDir[5] = { {0, 1, 2, 3} };                          // Type 5
}
int answer = INT_MAX;
bool IsValid(int x, int y)
{
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}
void MakeWall(int x, int y,vector<int>dir)
{
    int cur_x = x;
    int cur_y = y;
    for (int i = 0; i < dir.size(); i++)
    {
        cur_x = x;
        cur_y = y;
        int tx = dx[dir[i]];
        int ty = dy[dir[i]];
        while (true)
        {
            int nx = tx + cur_x;
            int ny = ty + cur_y;
            if (!IsValid(nx , ny )) break;
        
            if (rooms[ny][nx] == 6)break;
            rooms[ny][nx] = -1;
            cur_x = nx;
            cur_y = ny;
        }
    }
}
void Calc()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (rooms[i][j] == 0)cnt++;
        }
    }
    answer = min(answer, cnt);
}
void Simulation(int cnt,int idx)
{
    if (idx == cctvs.size())
    {
        Calc();
        return;
    }
    for (int i = idx; i < cctvs.size(); i++)
    {
        int num = cctvs[i].num;
        for (int j = 0; j < cctvDir[num].size(); j++)
        {
            int x = cctvs[i].x;
            int y = cctvs[i].y;
            vector<int> tmp = cctvDir[num][j];
            vector<vector<int>> before = rooms;
            MakeWall(x, y, tmp);
            Simulation(cnt + 1,i+1);
            rooms = before;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n >> m;
    rooms.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> rooms[i][j];
            if (rooms[i][j] >= 1 && rooms[i][j] <= 5)
            {
                cctvs.emplace_back(CCTV{ i,j,0,rooms[i][j] });
            }
        }
    }
    Init();
    Simulation(0,0);
    cout << answer;
    return 0;
}