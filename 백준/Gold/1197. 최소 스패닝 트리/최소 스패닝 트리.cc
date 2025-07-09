#include <bits/stdc++.h>
using namespace std;

vector<int> p;

int find(int x)
{
    if (p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool Uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (p[u] == p[v]) p[u]--;
    
    if (p[u] < p[v])
    {
        p[v] = u;
    }
    else
    {
        p[u] = v;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges(m);
    p.resize(n + 1, -1);
    int n1 = 0, n2 = 0, cost = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> n1 >> n2 >> cost;
        edges[i] = { cost,n1,n2 };
    }
    sort(edges.begin(), edges.end());
    int cnt = 0;
    int answer = 0;
    for (int i = 0; i < m; i++)
    {
       n1 = get<1>(edges[i]);
       n2 = get<2>(edges[i]);
       cost = get<0>(edges[i]);
       if (!Uni(n1, n2)) continue;
       answer += cost;
       cnt++;
       if (cnt == n - 1) break;
    }
    cout << answer;
    return 0;
}