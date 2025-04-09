#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    int width, length = 0;
    int candy, box = 0;
    while (t--)
    {
        cin >> candy >> box;
        priority_queue<int> pq;
        int answer = 0;
        for (int i = 0; i < box; i++)
        {
            cin >> length >> width;
            pq.push(length * width);
        }
        while (true)
        {
            candy -= pq.top();
            pq.pop();
            answer++;
            if (candy <= 0) break;
        }
        cout << answer << '\n';
    }

    return 0;
}