#include <bits/stdc++.h>
using namespace std;
#define INF 99999999

void dijkstra(vector<vector<pair<int, int>>>& graph, int sPoint, int ePoint)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(graph.size(), INF);

    dist[sPoint] = 0;
    pq.push(make_pair(0, sPoint));
    vector<int> parent(graph.size(), -1);
    while (!pq.empty())
    {

        int cur_node = pq.top().second;
        int cur_dist = -pq.top().first;
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
                parent[next_node] = cur_node;
                pq.push(make_pair(-next_dist, next_node));  
            }
        }
    }
    
    vector<int> path;
    int num = 0;
    int tmp = ePoint;
    path.emplace_back(ePoint);
    while (num != sPoint)
    {
        num = parent[tmp];
        path.emplace_back(num);
        tmp = num;
    }
    cout << dist[ePoint] << '\n' << path.size() << '\n';
    for (int i = path.size()-1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
  
    int point, m = 0;
    cin >> point >> m;
    int sPoint, ePoint = 0;
    vector<vector<pair<int,int>>> graph(point + 1);

    int from, to, cost = 0;
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to >> cost;
        graph[from].emplace_back(make_pair(to, cost));
    }
    cin >> sPoint >> ePoint;

    dijkstra(graph, sPoint, ePoint);
    return 0;
}