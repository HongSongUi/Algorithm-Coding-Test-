#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> arr;

void BFS()
{
    vector<bool> visited(n + 1, false);
    visited[1] = true; 
    queue<pair<int, int>> q;
    q.push(make_pair(1, 0));
    set<int> friendList;
    while (!q.empty())
    {
        int cur_node = q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        if (cur_depth < 3 && cur_depth>0)
        {
            friendList.insert(cur_node);
        }
        for (int i = 0; i < arr[cur_node].size(); i++)
        {
            int next_node = arr[cur_node][i];
            if (!visited[next_node])
            {
                visited[next_node] = true;
                q.push(make_pair(next_node, cur_depth + 1));
            }
        }
    }
    cout << friendList.size();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n;
    int m = 0;
    arr.resize(n + 1);
    cin >> m;
    int from = 0, to = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        arr[from].emplace_back(to);
        arr[to].emplace_back(from);
    }
    BFS();
    return 0;
}