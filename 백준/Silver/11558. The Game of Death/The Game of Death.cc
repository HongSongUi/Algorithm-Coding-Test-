#include <bits/stdc++.h>
using namespace std;
int n = 0;
void BFS(vector<int>& graph)
{
    queue<pair<int, int>>q;
    q.push(make_pair(1, 0));
    vector<bool> visited(n+1, false);
    visited[1] = true;
    int d = 0;
    while (!q.empty())
    {
        int cur_p = q.front().first;
        int cur_d = q.front().second;
        q.pop();
        if (cur_p == n)
        {
            d = cur_d;
            break;
        }
        int next_p = graph[cur_p];
        int next_d = cur_d + 1;
        if (!visited[next_p])
        {
            q.push(make_pair(next_p, next_d));
            visited[next_p] = true;
        }
        
    }
    cout << d << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> graph(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> graph[i];
        }
        BFS(graph);
    }
    return 0;
}