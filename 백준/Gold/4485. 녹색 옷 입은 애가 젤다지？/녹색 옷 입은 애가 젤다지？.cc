#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using ll = long long;
ll INF = LLONG_MAX;


vector<int> dx = { 1,-1,0,0 };
vector<int> dy = { 0,0,1,-1 };


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  
    int n = 0, tc = 1;
    while (true)
    {
        cin >> n;
        if (n == 0) break;

        vector<vector<int>> grid(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        vector<vector<ll>> dist(n, vector<ll>(n, INF));
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

        dist[0][0] = grid[0][0];
        pq.emplace(dist[0][0], 0, 0);

        while (!pq.empty()) 
        {
            ll cost = get<0>(pq.top());
            int r = get<1>(pq.top());
            int c = get<2>(pq.top());
            pq.pop();
 

            if (cost > dist[r][c]) continue;

            for (int d = 0; d < 4; d++) 
            {
                int nr = r + dx[d];
                int nc = c + dy[d];
                if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                ll nc_cost = cost + grid[nr][nc];
                if (nc_cost < dist[nr][nc]) 
                {
                    dist[nr][nc] = nc_cost;
                    pq.emplace(nc_cost, nr, nc);
                }
            }
        }
        cout << "Problem " << tc<< ": " << dist[n - 1][n - 1] << "\n";
        tc++;
    }
    return 0;
}
