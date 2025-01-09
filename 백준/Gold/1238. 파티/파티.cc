#include <bits/stdc++.h>
using namespace std;

int dijkstra(int start, int dest, vector<vector<pair<int, int>>>& graph)
{
    vector<int> dist(graph.size(), 99999999);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();
        if (cur_node == dest)
        {
            break;
        }
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = graph[cur_node][i].second + cur_dist;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair(-next_dist, next_node));
            }
        }
    }
    return dist[dest];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rCount, pCount, target;
    cin >> pCount >> rCount >> target;

    vector<vector<pair<int, int>>> graph(rCount + 1);
    int from, to, cost = 0;
    for (int i = 0; i < rCount; i++)
    {
        cin >> from >> to >> cost;
        graph[from].emplace_back(make_pair(to, cost));
    }
    
    vector<int> buff(pCount+1,0);
    for (int i = 1; i <= pCount; i++)
    {
        buff[i] = dijkstra(i, target, graph);
    }
    for (int i = 1; i <= pCount; i++)
    {
        buff[i] += dijkstra(target, i, graph);
    }
    cout << *max_element(buff.begin(), buff.end());
    return 0;
}