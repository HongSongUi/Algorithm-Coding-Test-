#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<vector<int>> graph;
vector<vector<int>> tmp;
int max_cnt = 0;



void BFS(int p)
{
    vector<bool> visited(n + 1);
    queue<pair<int, int>> q;
    q.push(make_pair(p, 0));
    visited[p] = true;
    int cnt = 0;
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
                cnt++;
                visited[next] = true;
                q.push(make_pair(next, d + 1));
            }
        }
    }
    max_cnt = max(max_cnt, cnt);
    tmp[cnt].emplace_back(p);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> m;
    graph.resize(n + 1);
    tmp.resize(n + 1);

    int s = 0;
    int e = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> e;
        graph[e].emplace_back(s);
    }
    for (int i = 1; i <= n; i++)
    {
        BFS(i);
    }
    sort(tmp[max_cnt].begin(), tmp[max_cnt].end());
    for (int i = 0; i < tmp[max_cnt].size(); i++)
    {
        cout << tmp[max_cnt][i] << ' ';
    }
    return 0;
}