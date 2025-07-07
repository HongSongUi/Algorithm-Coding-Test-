#include <bits/stdc++.h>
using namespace std;

int n = 0, m = 0;
vector<vector<pair<int, int>>> graph;
int BFS(int s, int e)
{
    vector<bool> visited(n + 1, false);
    queue<pair<int, int>> q;
    q.push(make_pair(s, 0));
    visited[s] = true;
    int dist = 0;
    while (!q.empty())
    {
        int cur_node = q.front().first;
        int cur_dist = q.front().second;

        if (cur_node == e)
        {
            dist = cur_dist;
            break;
        }
        q.pop();
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;
            if (!visited[next_node])
            {
                visited[next_node] = true;
                q.push(make_pair(next_node, next_dist));
            }
        }
        
    }
    return dist;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    graph.resize(n + 1);

    int dist = 0;
    int node1 = 0;
    int node2 = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> node1 >> node2 >> dist;
        graph[node1].emplace_back(make_pair(node2, dist));
        graph[node2].emplace_back(make_pair(node1, dist));
    }

    while (m--)
    {
        cin >> node1 >> node2;
        
        cout << BFS(node1, node2) << '\n';
    }
    
    return 0;
}