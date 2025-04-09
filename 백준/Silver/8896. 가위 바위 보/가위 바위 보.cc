#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;
    int r = 0;
    while (t--)
    {
        cin >> r;
        vector<pair<string, bool>> robots;
        string str = "";
        int k = 0;
        for (int i = 0; i < r; i++)
        {
            cin >> str;
            k = str.length();
            robots.emplace_back(make_pair(str, true));
        }
        for (int i = 0; i < k; i++)
        {
            vector<vector<int>> tmp(3);
            bool Rock = false;
            bool Scissors = false;
            bool Paper = false;
            for (int j = 0; j < r; j++)
            {
                if (!robots[j].second)
                {
                    continue;
                }
                char ch = robots[j].first[i];
                
                if (ch == 'R')
                {
                    tmp[0].emplace_back(j);
                    Rock = true;
                }
                if (ch == 'S')
                {
                    tmp[1].emplace_back(j);
                    Scissors = true;
                }
                if (ch == 'P')
                {
                    tmp[2].emplace_back(j);
                    Paper = true;
                }
            }
            if ((Rock && Scissors && Paper) ||((Rock && !Scissors && !Paper) || (!Rock && Scissors && !Paper) || (!Rock && !Scissors && Paper)))
            {
                continue;
            }
            if (Rock && Scissors)
            {
                for (int i = 0; i < tmp[1].size(); i++)
                {
                    robots[tmp[1][i]].second = false;
                }
            }
            else if (Rock && Paper)
            {
                for (int i = 0; i < tmp[0].size(); i++)
                {
                    robots[tmp[0][i]].second = false;
                }
            }
            else if (Scissors && Paper)
            {
                for (int i = 0; i < tmp[2].size(); i++)
                {
                    robots[tmp[2][i]].second = false;
                }
            }
        }
        int answer = 0;
        int count = 0;
        for (int i = 0; i < robots.size(); i++)
        {
            if (robots[i].second)
            {
                answer = i + 1;
                count++;
            }
        }
        if (count == 1)
        {
            cout << answer << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    return 0;
}