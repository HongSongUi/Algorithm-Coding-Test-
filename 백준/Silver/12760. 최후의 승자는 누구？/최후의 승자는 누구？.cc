#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    vector<int> player(n, 0);
    vector<int> answer;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> cards[i][j];
        }
        sort(cards[i].rbegin(), cards[i].rend());
    }
    int max_win = 0;
    int max_value = 0;
    for (int i = 0; i < m; i++)
    { 
        max_value = 0;
        for (int j = 0; j < n; j++)
        {
            if (cards[j][i] > max_value)
            {
                max_value = cards[j][i];
            }
        }
        for (int j = 0; j < n; j++)
        {
            if (cards[j][i] == max_value)
            {
                player[j]++;
                if (player[j] > max_win)
                {
                    max_win = player[j];
                }
            }
        }    
    }
    for (int i = 0; i < player.size(); i++)
    {
        if (player[i] == max_win)
        {
            cout << i+1 <<' ';
        }
    }
    return 0;
}