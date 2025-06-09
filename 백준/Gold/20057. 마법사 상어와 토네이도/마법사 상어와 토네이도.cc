#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> left_dir = { {0,0,2,0,0},{0,10,7,1,0},{5,-1,-1,-1,0},{0,10,7,1,0},{0,0,2,0,0} };
vector<vector<int>> right_dir = { {0,0,2,0,0},{0,1,7,10,0},{0,-1,-1,-1,5},{0,1,7,10,0},{0,0,2,0,0} };
vector<vector<int>> top_dir = { {0,0,5,0,0},{0,10,-1,10,0},{2,7,-1,7,2},{0,1,-1,1,0},{0,0,0,0,0} };
vector<vector<int>> bottom_dir= { {0,0,0,0,0},{0,1,-1,1,0},{2,7,-1,7,2},{0,10,-1,10,0} ,{0,0,5,0,0} };
vector<pair<int, int>> direction = { {0,-1},{1,0},{0,1},{-1,0} };//y,x
vector<vector<long long>> arr;
int n = 0;

bool IsValid(int x, int y)
{
    return (x >= 0 && x < n) && (y >= 0 && y < n);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int cur_x = n / 2;
    int cur_y = n / 2;
    int idx = 0;
    pair<int, int> dir;
    int limit = 1;
    int count = 0;
    vector<vector<int>> tmp;
    long long answer = 0;
    while (true)
    {
       
        dir = direction[idx];
        cur_x += dir.second;
        cur_y += dir.first;
        if (arr[cur_y][cur_x] != 0)
        {
            long long dust = arr[cur_y][cur_x];
            long long remain_dust = dust;
            pair<int, int> alpha;
            int nx = 0;
            int ny = 0;
            if (idx == 0)
            {
                tmp = left_dir;
                alpha = make_pair(cur_y, cur_x - 1);
            }
            else if (idx == 1)
            {
                tmp = bottom_dir;
                alpha = make_pair(cur_y+1, cur_x);
            }
            else if (idx == 2)
            {
                tmp = right_dir;
                alpha = make_pair(cur_y , cur_x+1);
            }
            else
            {
                tmp = top_dir;
                alpha = make_pair(cur_y-1, cur_x);
            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (tmp[i][j] == 0 || tmp[i][j] == -1) continue;
                    int tx = j - 2;
                    int ty = i - 2;
                    ny = cur_y + ty;
                    nx = cur_x + tx;
                    long long move_dust = dust * tmp[i][j] / 100;
                    if (IsValid(nx, ny))
                    {
                        arr[ny][nx] += move_dust;
                        remain_dust -= move_dust;
                    }
                    else
                    {
                        answer += move_dust;
                        remain_dust -= move_dust;
                    }
                }
            }
            arr[cur_y][cur_x] = 0;
            if (IsValid(alpha.second, alpha.first))
            {
                arr[alpha.first][alpha.second] += remain_dust;
            }
            else
            {
                answer += remain_dust;
            }
        }
        count++;
        if (count == limit)
        {
            count = 0;
            idx++;
            idx %= 4;
            if (idx % 2 == 0) limit++;
        }
        if (cur_y == 0 && cur_x == 0) break;   
    }
    cout << answer;
    return 0;
}