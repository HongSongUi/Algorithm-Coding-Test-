#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start, int dest, vector<vector<pair<int, int>>>& graph, vector<int> & dist)
{
    priority_queue<pair<int, int>> q;
    q.push(make_pair(0, start));
    dist[start] = 0;
    while (!q.empty())
    {
        int cur_dist = -q.top().first;
        int cur_node = q.top().second;
        q.pop();
        if (cur_node == dest)
        {
            cout << dist[dest] << '\n';
            break;
        }
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second + cur_dist;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                q.push(make_pair(-next_dist, next_node));
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0;
    cin >> n;
    cin >> count;
    vector<vector<pair<int, int>>> graph(n+1);
   
    int from, to, cost = 0;
    int start, dest = 0;
    for (int i = 0; i < count; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    cin >> start >> dest;
    vector<int> dist(graph.size(), 99999999);
    dijkstra(start, dest, graph,dist);
  
    return 0;
}