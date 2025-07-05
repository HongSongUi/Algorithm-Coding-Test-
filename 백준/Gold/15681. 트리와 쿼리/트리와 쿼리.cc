#include <bits/stdc++.h>
using namespace std;

int n = 0, r = 0, q = 0;
vector<vector<int>> graph;
vector<int> counter;
vector<bool> visited;

int DFS(int p)
{
    visited[p] = true;
    
    for (int i = 0; i < graph[p].size(); i++)
    {
        int next = graph[p][i];
        if (!visited[next])
        {
            counter[p] += DFS(next);
        }
    }
    return  counter[p];
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> n >> r >> q;
    graph.resize(n + 1);
    counter.resize(n + 1,1);
    visited.resize(n + 1, false);
    int node1 = 0;
    int node2 = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> node1 >> node2;
        graph[node1].emplace_back(node2);
        graph[node2].emplace_back(node1);
    }
    DFS(r);
    int node = 0;
    while (q--)
    {
        cin >> node;
        cout << counter[node] << '\n';
    }
    return 0;
}