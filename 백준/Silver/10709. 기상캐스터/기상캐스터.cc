#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m, -1));
    string s = "";
    int num = -1;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        num = -1;
        time = 0;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == 'c')
            {
                num = j;
                time = 0;
                graph[i][j] = time;
            }
            else if (s[j] == '.' && j>num && num != -1)
            {
                time++;
                graph[i][j] = time;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j] << ' ';
        }
        cout << '\n';
    }
   
    return 0;
}