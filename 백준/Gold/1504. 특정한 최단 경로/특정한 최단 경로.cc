#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
vector<vector<pair<int, int>>> graph;

int dijkstra(int start, int end)
{
    priority_queue<pair<int, int>> q;
    vector<int> dist(graph.size(), INF);
    dist[start] = 0;
    q.push(make_pair(start, 0));
    while (!q.empty())
    {
        int cur_dist = -q.top().second;
        int cur_node = q.top().first;
        q.pop();
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second + cur_dist;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                q.push(make_pair(next_node, -next_dist));
            }
        }
    }
    return dist[end];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;
    
    int from, to, cost;
    int via1, via2;
    int end = N;
    graph.resize(N + 1);
    for (int i = 0; i < E; i++)
    {
        cin >> from >> to >> cost;
        graph[from].emplace_back(make_pair(to, cost));
        graph[to].emplace_back(make_pair(from, cost));
    }
    cin >> via1 >> via2;
    
    int total1 = dijkstra(1, via1)+ dijkstra(via1, via2) + dijkstra(via2, end);
    int total2 = dijkstra(1, via2) + dijkstra(via2, via1) + dijkstra(via1, end);
    if ((total1 >= INF) || (total2 >= INF))
    {
        cout << -1;
    }
    else
    {
        cout << min(total1, total2);
    }
    return 0;
}