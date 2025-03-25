#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int answer = 0;
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        for (int j = 0; j < m; j++)
        {
            arr[i][j] = tmp[j] - '0';
        }
    }

    while (true)
    {
        int x = -1;
        int y = -1;
        bool isFind = false;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (arr[i][j] == 1)
                {
                    x = j;
                    y = i;
                    isFind = true;
                    break;
                }
            }
            if (isFind)break;
        }
        if (!isFind)
        {
            break;
        }
        for (int i = 0; i <= y; i++)
        {
            for (int j = 0; j <= x; j++)
            {
                if (arr[i][j] == 0)
                {
                    arr[i][j] = 1;
                }
                else if (arr[i][j] == 1)
                {
                    arr[i][j] = 0;    
                }
            }
        }
        answer++;
    }
    cout << answer;
    return 0;
}
