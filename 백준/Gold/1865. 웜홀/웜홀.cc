#include <bits/stdc++.h>
using namespace std;

#define INF 9999999

struct Edge
{
    int from, to, cost;
};

bool BellmanFord(int pNum , vector<Edge>& graph)
{
    vector<int> dist(pNum+1, INF);
    dist[1] = 0;
    
    for (int i = 1; i <= pNum; i++)
    {
        for (int j = 0; j < graph.size(); j++)
        {
            int from = graph[j].from;
            int to = graph[j].to;
            int cost = graph[j].cost;
            if (dist[to] > dist[from] + cost)
            {
                dist[to] = dist[from] + cost;   
                if (i == pNum)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tc = 0;
    cin >> tc;
    
    while (tc > 0)
    {
        int pNum, rNum, wNum;
        cin >> pNum >> rNum >> wNum;
        int start, end, cost;
        vector<Edge>graph;
        int size = graph.size();
        bool isGo = false;
        for (int i = 0; i < rNum; i++)
        {
            cin >> start >> end >> cost;
            graph.emplace_back(Edge{ start,end,cost });
            graph.emplace_back(Edge{ end,start,cost });
        }
        for (int i = 0; i < wNum; i++)
        {
            cin >> start >> end >> cost;
            graph.emplace_back(Edge{ start,end, -cost });
        }
       

        if (BellmanFord(pNum, graph)) 
        {
            cout << "YES\n";
        }
        else 
        {
            cout << "NO\n";
        }
        tc--;
    }
    return 0;
}