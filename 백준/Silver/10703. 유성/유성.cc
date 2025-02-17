#include <bits/stdc++.h>
using namespace std;

int r = 0, s = 0;
vector<pair<int, int>> m;
vector<vector<char>> picture;
priority_queue<pair<int, int>> pq;

void BFS()
{
    vector<pair<int, int>> t;
    for (int i = 0; i < m.size(); i++)
    {
        int curX = m[i].second;
        int curY = m[i].first;
        if (picture[curY + 1][curX] == '.')
        {
            t.emplace_back(make_pair(curY, curX));
        }
    }
    int falling = INT_MAX;
    for (int i = 0; i < t.size(); i++)
    {
        int curX = t[i].second;
        int curY = t[i].first;
        for (int j = curY + 1; j < r; j++)
        {
            if (picture[j][curX] == '#')
            {
                int num = j - curY - 1;
                if (num < falling)
                {
                    falling = num;
                }
            }
        }
    }
    while (!pq.empty())
    {
        int curX = pq.top().second;
        int curY = pq.top().first;
        pq.pop();
        picture[curY + falling][curX] = 'X';
        picture[curY][curX] = '.';
   }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cin >> r >> s;
    picture.resize(r, vector<char>(s));
    string temp;
    for (int i = 0; i < r; i++)
    {
        cin >> temp;
        for (int j = 0; j < s; j++)
        {
            if (temp[j] == 'X' )
            {
                m.emplace_back(make_pair(i, j));
                pq.push(make_pair(i, j));
            }
            picture[i][j] = temp[j];
        }
    }
    BFS();
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < s; j++)
        {
            cout << picture[i][j];
        }
        cout << '\n';
    }

    return 0;
}