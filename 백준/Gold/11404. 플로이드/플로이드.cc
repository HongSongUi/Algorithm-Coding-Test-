#include <bits/stdc++.h>
using namespace std;
#define INF 99999999


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int point, road = 0;
    cin >> point >> road;
    vector<vector<int>> graph(point + 1, vector<int>(point + 1, INF));
  
    int from, to, cost = 0;

    for (int i = 0; i < road; i++)
    {
        cin >> from >> to >> cost;
        if (graph[from][to] != INF)
        {
            if (cost < graph[from][to])
            {
                graph[from][to] = cost;
            }
        }
        else
        {
            graph[from][to] = cost;
        }
        graph[from][from] = 0;
    }
    
    for (int i = 1; i < point + 1; i++)
    {
        for (int j = 1; j < point + 1; j++)
        {
            for (int k = 1; k < point + 1; k++)
            {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    for (int i = 1; i < graph.size(); i++)
    {
        for (int j = 1; j < graph.size(); j++)
        {
            if (graph[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}