#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<bool> wall(n + 1, false);
    
    int x = 0, y = 0;
    while (m--)
    {
        cin >> x >> y;
        for (int i = x; i < y; i++)
        {
            wall[i] = true;
        }
    }
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (wall[i] == false)
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}