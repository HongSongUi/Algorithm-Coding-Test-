#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<vector<int>> room(n, vector<int>(n, 0));
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        for (int j = 0; j < n; j++)
        {
            if (temp[j] == 'X')
            {
                room[i][j] = 1;
            }
        }
    }
    int length = 0;
    int width = 0;
    int answer1 = 0;
    int answer2 = 0;
    for (int i = 0; i < n; i++)
    {
        length = 0;
        width = 0;
        for (int j = 0; j < n; j++)
        {
            if (room[i][j] == 0)
            {
                length++;
            }
            else if (room[i][j] == 1)
            {
                if (length >= 2)
                {
                    answer1++;
                }
                length = 0;
            }
            if (room[j][i] == 0)
            {
                width++;
            }
            else if (room[j][i] == 1)
            {
                if (width >= 2)
                {
                    answer2++;
                }
                width = 0;
                
            }
        }
        if (length >= 2)
        {
            answer1++;
        }
        if (width >= 2)
        {
            answer2++;
        }
    }
    cout << answer1 << " " << answer2;
    return 0;
}