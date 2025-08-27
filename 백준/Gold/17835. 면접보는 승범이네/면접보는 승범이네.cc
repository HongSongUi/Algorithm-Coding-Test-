#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define INF 1e18
vector<vector<pair<int, int>>> graph;
vector<long long> dist;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    graph.resize(n + 1);
    int from, target, cost;
    for (int i = 0; i < m; i++)
    {
        cin >> from >> target >> cost;

        graph[target].emplace_back(make_pair(from, cost));
    }
    dist.resize(n + 1, INF);
    int num = 0;
    for (int i = 0; i < k; i++)
    {
        cin >> num;
        dist[num] = 0;
        pq.push(make_pair(0, num));
    }

    while (!pq.empty())
    {
        long long cur_dist = pq.top().first;
        int cur_node = pq.top().second;

        pq.pop();

        if (cur_dist > dist[cur_node])
        {
            continue;
        }
        for (int i = 0; i < graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i].first;
            long long next_dist = graph[cur_node][i].second + cur_dist;
            if (next_dist < dist[next_node])
            {
                dist[next_node] = next_dist;
                pq.push(make_pair(next_dist, next_node));
            }
        }
    }
    long long answer = 0;
    int tmp = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (answer < dist[i])
        {
            tmp = i;
            answer = dist[i];
        }

    }
    cout << tmp << '\n';
    cout << answer;
    return 0;
}
