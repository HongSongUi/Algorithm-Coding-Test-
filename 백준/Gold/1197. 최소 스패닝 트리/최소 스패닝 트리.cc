#include <bits/stdc++.h>
using namespace std;

vector<int>p;
int find(int x)
{
    if (p[x] ==x ) return x;
    return p[x] = find(p[x]);
}

bool isUnion(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)return false;
    p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 0, m = 0;
    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    vector<tuple<int, int, int>>edges(m);
    int node1, node2, cost;
    for (int i = 0; i < m; i++)
    {
        cin >> node1 >> node2 >> cost;
        edges[i] = { cost,node1,node2 };
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        int c = get<0>(edges[i]);
        if (!isUnion(u, v)) continue;
        answer+= c;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << answer;
    return 0;
}