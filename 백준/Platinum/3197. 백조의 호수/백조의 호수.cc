#include <bits/stdc++.h>
using namespace std;

int r, c;
vector<string> board;
vector<vector<bool>> waterVisited, swanVisited;
queue<pair<int, int>> waterQ, nextWaterQ;
queue<pair<int, int>> swanQ, nextSwanQ;
pair<int, int> swan1, swan2;

vector<int> dx = { -1, 1, 0, 0 };
vector<int> dy = { 0, 0, -1, 1 };

bool IsValid(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool MoveSwan()
{
    while (!swanQ.empty()) 
    {
        int x = swanQ.front().first;
        int y = swanQ.front().second;
        swanQ.pop();

        for (int i = 0; i < 4; i++) 
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || swanVisited[nx][ny]) continue;

            swanVisited[nx][ny] = true;
            if (board[nx][ny] == '.')
            {
                swanQ.push({ nx, ny });
            }
            else if (board[nx][ny] == 'X') 
            {
                nextSwanQ.push({ nx, ny });
            }
            else if (board[nx][ny] == 'L')
            {
                return true; 
            }
        }
    }
    return false;
}

void MeltIce() 
{
    while (!waterQ.empty()) 
    {
        int x = waterQ.front().first;
        int y = waterQ.front().second;
        waterQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!IsValid(nx, ny) || waterVisited[nx][ny]) continue;

            if (board[nx][ny] == 'X')
            {
                board[nx][ny] = '.';
                nextWaterQ.push({ nx, ny });
            }
            waterVisited[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> r >> c;
    board.resize(r);
    waterVisited.assign(r, vector<bool>(c, false));
    swanVisited.assign(r, vector<bool>(c, false));

    bool firstSwan = false;

    for (int i = 0; i < r; i++) 
    {
        cin >> board[i];
        for (int j = 0; j < c; j++) 
        {
            if (board[i][j] != 'X') 
            {
                waterQ.push({ i, j });
                waterVisited[i][j] = true;
            }
            if (board[i][j] == 'L')
            {
                if (!firstSwan)
                {
                    swan1 = { i, j };
                    swanQ.push({ i, j });
                    swanVisited[i][j] = true;
                    firstSwan = true;
                }
                else
                {
                    swan2 = { i, j };
                }
            }
        }
    }

    int days = 0;
    while (true) 
    {
        if (MoveSwan()) break;
        MeltIce();

        swanQ = nextSwanQ;
        waterQ = nextWaterQ;

        while (!nextSwanQ.empty()) nextSwanQ.pop();
        while (!nextWaterQ.empty()) nextWaterQ.pop();

        days++;
    }

    cout << days << '\n';
    return 0;
}