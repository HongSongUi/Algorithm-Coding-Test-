#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int INF = 1000000000;




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    int n, m;
    cin >> n >> m;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) 
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++) 
    {
        int u, v, b;
        cin >> u >> v >> b;
        dist[u][v] = 0;
        if (b == 1) 
        {
            dist[v][u] = 0;
        }
        else
        {
            dist[v][u] = 1;
        }
    }

    for (int k = 1; k <= n; k++) 
    {
        for (int i = 1; i <= n; i++) 
        {
            for (int j = 1; j <= n; j++) 
            {
                if (dist[i][j] > dist[i][k] + dist[k][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while (Q--) 
    {
        int s, e;
        cin >> s >> e;
        cout << dist[s][e] << "\n";
    }
    return 0;
}
