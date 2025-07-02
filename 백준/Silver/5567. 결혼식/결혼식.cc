#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<vector<int>> graph;

int BFS()
{
    vector<bool> visited(n + 1);
    queue<pair<int,int>> q;
    visited[1] = true;
    q.push(make_pair(1, 0));
    int ret = 0;
    while (!q.empty())
    {
        int cur = q.front().first;
        int d = q.front().second;

        q.pop();

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i];
            if (!visited[next])
            {
                visited[next] = true;
                if (d + 1 <= 2) ret++;
                q.push(make_pair(next, d + 1));
            }
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin >> n >> m;
    graph.resize(n + 1);
    int s = 0;
    int e = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    cout << BFS();
    return 0;
}