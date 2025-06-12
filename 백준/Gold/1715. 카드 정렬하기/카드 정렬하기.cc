#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n = 0;
    cin >> n;
    priority_queue<int> pq;

    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        pq.push(-num);
    }
    int answer = 0;
    int cost = 0;
    while (pq.size() > 1)
    {
        cost = 0;
        for (int i = 0; i < 2; i++)
        {
            if (!pq.empty())
            {
                cost += -pq.top();
                pq.pop();
            }
        }
        answer += cost;
        if (pq.size() == 0) break;
        pq.push(-cost);
    }
    cout << answer;
    return 0;
}