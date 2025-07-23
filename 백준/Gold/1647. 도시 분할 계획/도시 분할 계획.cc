#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<tuple<int, int, int>> edges;
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
    if (u == v)
    {
        return false;
    }

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

    cin >> n >> m;
    edges.resize(m);
    p.resize(n + 1, -1);
    int a, b, cost;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> cost;
        edges[i] = make_tuple(cost, a, b);
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    int cnt = 0;
    int max_cost = 0;
    for (int i = 0; i < m; i++)
    {
        a = get<1>(edges[i]);
        b = get<2>(edges[i]);
        cost = get<0>(edges[i]);
        if (Uni(a, b))
        {
            answer += cost;
            cnt++;
            max_cost = max(max_cost, cost);
        }
      
        if (cnt == n - 1) break;
    }
    cout << answer - max_cost;
    return 0;
}