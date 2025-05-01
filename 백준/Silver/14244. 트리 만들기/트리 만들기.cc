#include <bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0, m = 0;
    
    cin >> n >> m;
    
    vector<vector<int>> graph(n);
    graph[0].emplace_back(1);
    for (int i = 2; i <= m; i++)
    {
        graph[1].emplace_back(i);
    }
    for (int i = m; i < n-1; i++)
    {
        graph[i].emplace_back(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        if (graph[i].size() == 0) continue;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << i << ' ' << graph[i][j] << '\n';
        }
    }
    return 0; 
}