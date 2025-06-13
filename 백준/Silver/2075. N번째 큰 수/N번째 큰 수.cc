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
        for (int j = 0; j < n; j++)
        {
            cin >> num;
            pq.push(-num);
            if (pq.size() > n)
            {
                pq.pop();
            }
        }
    }
    cout << -pq.top();
    return 0;
}