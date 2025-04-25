#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    int answer = 0;
    int x = 0, y = 0;
    map<int, int> x_lines, y_liens;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        x_lines[x]++;
        y_liens[y]++;
    }
    for (auto data : x_lines)
    {
        if (data.second >= 2)
        {
            answer++;
        }
    }
    for (auto data : y_liens)
    {
        if (data.second >= 2)
        {
            answer++;
        }
    }
    cout << answer;
    return 0;
}
