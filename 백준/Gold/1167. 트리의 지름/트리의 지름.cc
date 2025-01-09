#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int >> graph[100001];
vector<bool> visited(100001 , false);

pair<int,int> DFS(int point)
{
    visited[point] = true;
    int size = graph[point].size();
    pair<int, int> temp = { 0,point };
    for (int i = 0; i < size; i++)
    {
        int Npoint = graph[point][i].first;
        int d = graph[point][i].second;
        if (visited[Npoint] == false)
        {
            pair<int, int> dist = DFS(Npoint);
            dist.first += d;
            temp = max(temp, dist);

        }
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size = 0;
    cin >> size;
    int point = 0;
    string temp = "";
    for (int i = 1; i < size + 1; i++)
    {
        cin >> point;
        while (true) 
        {
            int neighbor, distance;
            cin >> neighbor;
            if (neighbor == -1)
            {
                break;
            }
            cin >> distance;
            graph[point].emplace_back(make_pair(neighbor, distance));
        }
    }
    
    pair<int, int> p = DFS(1);
    visited.assign(100001, false);
    int answer = DFS(p.second).first;
    cout << answer;
    return 0;
}