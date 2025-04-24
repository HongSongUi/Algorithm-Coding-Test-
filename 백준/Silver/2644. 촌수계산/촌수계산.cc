#include <bits/stdc++.h>
using namespace std;
int n = 0;
vector<vector<int>> arr;

void BFS(int start, int end)
{
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));
    int answer = -1;
    while (!q.empty())
    {
        int cur_node = q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        if (cur_node == end)
        {
            answer = cur_depth;
            break;
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
    cout << answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    cin >> n;
    arr.resize(n + 1);
    int answer = -1;
    int x = 0, y = 0;
    cin >> x >> y;
    int m = 0;
    cin >> m;
    int parent = 0, child = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> parent >> child;
        arr[child].emplace_back(parent);
        arr[parent].emplace_back(child);
    }
    BFS(x, y);
    return 0;
}