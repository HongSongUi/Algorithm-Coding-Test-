#include <bits/stdc++.h>
using namespace std;
#define INF 99999999
vector<vector<pair<int, int>>> graph;
vector<int> item;
int maxCount = -1;

void dijkstra(int limit, int pointCount , int start)
{
    int itemCount = 0;
    vector<int> dist(pointCount+1, INF);
    priority_queue<pair<int, int>>pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    
    while (!pq.empty())
    {
        int cur_point = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur_point])
        {
            continue;
        }
        for (int i = 0; i < graph[cur_point].size(); i++)
        {
            int next_point = graph[cur_point][i].first;
            int next_dist = graph[cur_point][i].second + cur_dist;
            if (next_dist < dist[next_point])
            {
                dist[next_point] = next_dist;
                pq.push(make_pair(-next_dist, next_point));
            }
        }
    }
    for (int i = 1; i < dist.size(); i++)
    {
        if (dist[i] != INF && dist[i] <= limit)
        {
            itemCount += item[i];
        }
    }
    maxCount = max(maxCount, itemCount);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, r = 0;
    cin >> n >> m >> r;
    graph.resize(n+1);
    item.resize(n+1);
    for (int i = 1; i < n+1; i++)
    {
        cin >> item[i];
    }
    int from, to, cost = 0;
    for (int i = 0; i < r; i++)
    {
        cin >> from >> to >> cost;
        graph[from].emplace_back(make_pair(to, cost));
        graph[to].emplace_back(make_pair(from, cost));
    }
    for (int i = 1; i < n + 1; i++)
    {
        dijkstra(m, n, i);
    }
    cout << maxCount;
    return 0;
}