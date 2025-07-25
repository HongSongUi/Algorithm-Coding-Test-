#include <bits/stdc++.h>
using namespace std;

vector<int>p;

int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}

bool IsUnion(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return true;
    p[u] = v;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> edges(m);
    
    p.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    int num1 = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> num1;
        p[num1] = 0;
    }
    int num2 = 0;
    int cost = 0;

    for (int i = 0; i < m; i++)
    {
        cin >> num1 >> num2 >> cost;
        edges[i] = { cost,num1,num2 };
    }
    sort(edges.begin(), edges.end());
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = get<1>(edges[i]);
        int v = get<2>(edges[i]);
        int c = get<0>(edges[i]);
        if (IsUnion(u, v)) continue;
        
        answer += c;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << answer;

    return 0;
}