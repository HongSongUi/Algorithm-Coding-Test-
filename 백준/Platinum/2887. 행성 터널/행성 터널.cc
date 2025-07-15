#include <bits/stdc++.h>
using namespace std;

struct Planet
{
    int idx;
    int x, y, z;
};
vector<int> p;

int find(int x)
{
    if (p[x] == x) return x;
    return p[x] = find(p[x]);
}
bool Uni(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v) return false;

    p[v] = u;
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       
    int n = 0;
    cin >> n;
    p.resize(n, -1);
    vector<Planet> planets(n);
    for (int i = 0; i < n; i++)
    {
        planets[i].idx = i;
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
        p[i] = i;
    }
    vector<tuple<int, int, int>>edges;
    //x
    sort(planets.begin(), planets.end(), [](const Planet& a, const Planet& b) {
        return a.x < b.x;
        });
    for (int i = 0; i < n - 1; i++) 
    {
        int cost = abs(planets[i].x - planets[i + 1].x);
        edges.push_back({ cost, planets[i].idx, planets[i + 1].idx });
    }  
    //y
    sort(planets.begin(), planets.end(), [](const Planet& a, const Planet& b) {
        return a.y < b.y;
        });
    for (int i = 0; i < n - 1; i++) 
    {
        int cost = abs(planets[i].y - planets[i + 1].y);
        edges.push_back({ cost, planets[i].idx, planets[i + 1].idx });
    }

    // z 기준 정렬
    sort(planets.begin(), planets.end(), [](const Planet& a, const Planet& b) {
        return a.z < b.z;
        });
    for (int i = 0; i < n - 1; i++) {
        int cost = abs(planets[i].z - planets[i + 1].z);
        edges.push_back({ cost, planets[i].idx, planets[i + 1].idx });
    }

    sort(edges.begin(), edges.end());
    long long total = 0;
    int cnt = 0;
    int n1, n2, cost;
    for (int i = 0; i <edges.size(); i++)
    {
        n1 = get<1>(edges[i]);
        n2 = get<2>(edges[i]);
        cost = get<0>(edges[i]);
        if (!Uni(n1, n2)) continue;
        total += cost;
        cnt++;
        if (cnt == n - 1) break;
    }
    cout << total << '\n';
    return 0;
}