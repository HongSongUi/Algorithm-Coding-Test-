#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m = 0;
    cin >> n >> m;
    vector<int> dist(n + 1, -1);
    queue<int> q;

    int num = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        dist[num] = 0;
        q.push(num);
    }
    int answer = 0;
    int maxBit = 0;
    int temp = n;
    while (temp > 0)
    {
        temp >>= 1;
        maxBit++;
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < maxBit; i++)
        {
            int next = cur ^ (1 << i);
            if (next > n || dist[next] != -1)
            {
                continue;
            }

            dist[next] = dist[cur] + 1;
            answer = max(answer, dist[next]);
            q.push(next);
        }
    }
    cout << answer;
    return 0;
}