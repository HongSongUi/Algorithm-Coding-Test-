#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> levelMin, levelMax;
int width = 1;

void InOrder(int node, int d)
{
    if (node == -1) return;

    InOrder(graph[node][0], d + 1);

    levelMin[d] = min(levelMin[d], width);
    levelMax[d] = max(levelMax[d], width);
    width++;

    InOrder(graph[node][1], d + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       
    int n = 0;
    cin >> n;
    graph.resize(n + 1);
    levelMin.resize(n + 1,INT_MAX);
    levelMax.resize(n + 1, 0);
    int p, r, l;
    vector<bool> isChild(n + 1, false);
    for (int i = 0; i < n; i++)
    {
        cin >> p >> l >> r;
        graph[p].emplace_back(l);
        graph[p].emplace_back(r);
        if (r != -1)
        {
            isChild[r] = true;
        }
        if (l != -1)
        {
            isChild[l] = true;
        }
    }
    int root = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!isChild[i])
        {
            root = i;
        }
    }
    InOrder(root, 1);
    int lev = 0;
    int max_width = 0;
    for (int i = 1; i <= n; i++)
    {
        if (levelMax[i] == 0) continue;
        int tmp = levelMax[i] - levelMin[i] + 1;
        if (tmp > max_width)
        {
            max_width = tmp;
            lev = i;
        }
    }
    cout << lev << ' ' << max_width;
    return 0;
}