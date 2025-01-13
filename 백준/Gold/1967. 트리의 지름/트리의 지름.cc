#include <bits/stdc++.h>
using namespace std;

pair<int,int> DFS(int start, vector<vector<pair<int, int>>>& tree)
{
    vector<bool> visited(tree.size());
    int max_dist = -1;
    int fNode = 0;
    stack<pair<int,int>> buff;
    visited[start] = true;
    buff.push(make_pair(start, 0));
    while (!buff.empty())
    {
        int cur_node = buff.top().first;
        int cur_dist = buff.top().second;
        if (cur_dist > max_dist)
        {
            max_dist = cur_dist;
            fNode = cur_node;
        }
        buff.pop();
        for (int i = 0; i < tree[cur_node].size(); i++)
        {
            int next_node = tree[cur_node][i].first;
            int next_dist = tree[cur_node][i].second + cur_dist;
            if (visited[next_node] == false)
            {
                buff.push(make_pair(next_node, next_dist));
                visited[next_node] = true;
            }
        }
    }

    return make_pair(fNode, max_dist);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int nCount = 0;
    cin >> nCount;
    vector<vector<pair<int, int>>> tree(nCount + 1);

    int parent, child, cost;
    for (int i = 0; i < nCount - 1; i++)
    {
        cin >> parent >> child >> cost;
        tree[parent].emplace_back(make_pair(child, cost));
        tree[child].emplace_back(make_pair(parent, cost));
    }
    pair<int,int> p = DFS(1, tree);
    int answer = DFS(p.first, tree).second;
    cout << answer;
    return 0;
}