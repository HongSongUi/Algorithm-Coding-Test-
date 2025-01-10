#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

void dijkstra(int start, vector<vector<pair<int, int>>>& graph, vector<int> &dist)
{
   
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur_dist = -pq.top().first;
        int cur_node = pq.top().second;
        
        pq.pop();
  
        if (cur_dist > dist[cur_node])
        {
            continue;
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
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int pNum = 0;
    int rNum = 0;
    int sPoint = 0;

    cin >> pNum >> rNum;
    cin >> sPoint;

    vector<vector<pair<int, int>>> graph(pNum+1);

    int from, target, cost;

    for (int i = 0; i < rNum; i++)
    {
        cin >> from >> target >> cost;
        graph[from].emplace_back(make_pair(target, cost));
    }
    vector<int>dist(graph.size(), INF);
    dijkstra(sPoint, graph, dist);
    for (int i = 1; i <= pNum; i++) 
    {
        if (dist[i] == INF) 
        {
            cout << "INF\n";
        }
        else 
        {
            cout << dist[i] << '\n';
        }
    }
    return 0;
}