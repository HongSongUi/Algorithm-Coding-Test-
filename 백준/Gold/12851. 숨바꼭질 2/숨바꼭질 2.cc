#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

void BFS(int sPoint, int ePoint)
{    
    if (sPoint == ePoint)
    {
        cout << 0 << '\n' << 1;
        return;
    }
    vector<int> visited(100001, INF);
    queue<pair<int, int>>q;
    visited[sPoint] = true;
    q.push(make_pair(sPoint, 0));
    
    int d = 0;
    int n = 0;

    while (!q.empty())
    {
        int cur_point = q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        if (ePoint == cur_point)
        {
            d = cur_depth;
            n++;
        }
        int back = cur_point - 1;
        int front = cur_point + 1;
        int doub = cur_point * 2;
        if ((front >= 0 && front <= 100000) && cur_depth <= visited[front])
        {
            q.push(make_pair(front, cur_depth + 1));
            visited[front] = cur_depth;
        }
        if ((back >= 0 && back <= 100000) &&  cur_depth <= visited[back])
        {
            q.push(make_pair(back, cur_depth + 1));
            visited[back] = cur_depth;
        }
        if ((doub >= 0 && doub <= 100000) && cur_depth <= visited[doub])
        {
            q.push(make_pair(doub, cur_depth + 1));

            visited[doub] = cur_depth;
           
        }
    }
    cout << d << '\n' << n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k = 0;
    cin >> n >> k;
    BFS(n, k);
    return 0;
}