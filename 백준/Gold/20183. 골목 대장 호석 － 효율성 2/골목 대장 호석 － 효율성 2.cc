#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long;

ll INF = LLONG_MAX;

struct Edge 
{
    int to;
    ll cost;
};

int N, M, A, B;
ll C;
vector<vector<Edge>> adj;

bool canGo(ll maxEdgeCost) {
    vector<ll> dist(N + 1, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    dist[A] = 0;
    pq.push(make_pair( 0, A ));
    while (!pq.empty()) 
    {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (cur_dist > dist[cur_node]) continue;
        if (cur_node == B && cur_dist <= C) return true;
        for (auto& e : adj[cur_node])
        {
            if (e.cost > maxEdgeCost) continue;
            if (cur_dist + e.cost < dist[e.to] && cur_dist + e.cost <= C)
            {
                dist[e.to] = cur_dist + e.cost;
                pq.push(make_pair( dist[e.to], e.to ));
            }
        }
    }
    return false;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> A >> B >> C;
    adj.resize(N + 1);

    ll mxCost = 0;
    int u, v;
    ll w;
    for (int i = 0; i < M; i++) 
    {
        cin >> u >> v >> w;
        adj[u].emplace_back(Edge{ v,w });
        adj[v].emplace_back(Edge{ u,w });
        mxCost = max(mxCost, w);
    }
    ll lo = 1;
    ll hi = mxCost, ans = -1;
    ll mid = 0;
    while (lo <= hi) 
    {
        mid = (lo + hi) / 2;
        if (canGo(mid))
        { 
            ans = mid; hi = mid - 1; 
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << ans;
    return 0;
}
