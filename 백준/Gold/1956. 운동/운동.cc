#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

const int INF = 1e9;




int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    int v, e;
    cin >> v >> e;

    vector<vector<int>> dist(v + 1, vector<int>(v + 1, INF));

    int a, b, c;
    for (int i = 0; i  <e; i++) 
    {
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    for (int k = 1; k <= v; k++) 
    {
        for (int i = 1; i <= v; i++) 
        {
            for (int j = 1; j <= v; j++) 
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= v; i++) 
    {
        if (dist[i][i] < ans) 
        {
            ans = dist[i][i];
        }
    }

    if (ans == INF)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
    return 0;
}
