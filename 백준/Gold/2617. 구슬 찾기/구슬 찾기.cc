#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;

void DFS(int idx, vector<vector<int>>& arr, int& cnt)
{
    visited[idx] = true;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        int next = arr[idx][i];
        if (!visited[next])
        {
            cnt++;
            DFS(next, arr, cnt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
       
    int n = 0, m = 0;
    cin >> n >> m;
    visited.resize(n + 1);
    vector<vector<int>> heavy(n + 1);
    vector<vector<int>> light(n + 1);
    int b1, b2;
    for (int i = 0; i < m; i++)
    {
        cin >> b1 >> b2;
        heavy[b2].emplace_back(b1);
        light[b1].emplace_back(b2);
    }
    int limit = n / 2;
    int cnt = 0;
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        fill(visited.begin(), visited.end(), false);
        cnt = 0;
        DFS(i, heavy, cnt);
        if (cnt > limit)
        {
            answer++;
            continue;
        }
        fill(visited.begin(), visited.end(), false);
        cnt = 0;
        DFS(i, light, cnt);
        if (cnt > limit)
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}