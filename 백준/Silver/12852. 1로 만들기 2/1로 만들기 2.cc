#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> answer;
vector<bool> visited(1000001, false);
vector<int> parent;
void BFS(int num)
{
    visited[num] = true;
    queue<pair<int, int>>q;
    q.push(make_pair(num, 0));
    
    int depth = INT_MAX;
    while (!q.empty())
    {
        int cur_num = q.front().first;
        int cur_depth = q.front().second;
        q.pop();
        if (cur_num == 1)
        {
            break;
        }

        int next_num = 0;
        if (cur_num % 3 == 0)
        {
            next_num = cur_num / 3;
            if (!visited[next_num])
            {
                visited[next_num] = true;
                q.push(make_pair(next_num, cur_depth + 1));
                parent[next_num] = cur_num;
            }
        }
        if (cur_num % 2 == 0)
        {
            next_num = cur_num / 2;
            if (!visited[next_num])
            {
                visited[next_num] = true;
                q.push(make_pair(next_num, cur_depth + 1));
                parent[next_num] = cur_num;

            }
        }
        next_num = cur_num - 1;
        if (next_num>=0&&!visited[next_num])
        {
            visited[next_num] = true;
            q.push(make_pair(next_num, cur_depth + 1));
            parent[next_num] = cur_num;
        }
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    parent.resize(n + 1, -1);
    BFS(n);

    vector<int> path;

    for (int node = 1; node != -1; node = parent[node])
    {
        path.emplace_back(node);
    }
    reverse(path.begin(), path.end());
    cout << path.size() - 1 << '\n';
    for (int i = 0; i < path.size(); i++)
    {
        cout << path[i] << ' ';
    }

    return 0;
}
