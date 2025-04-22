#include <bits/stdc++.h>
using namespace std;
int n, m = 0;
vector<vector<int>> A;
vector<vector<int>> B;

bool IsVaild(int x, int y)
{
   
    return (x + 3 <= m && y + 3 <= n);
}

void ReverseMatrix(int x, int y)
{
    for (int i = y; i < y + 3; i++)
    {
        for (int j = x; j < x + 3; j++)
        {
            A[i][j] = -1 * (A[i][j] - 1);
           
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    
    A.resize(n, vector<int>(m));
    B.resize(n, vector<int>(m));
    string tmp = "";
    int num = 0;
    int count = 0;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin,tmp);
        num = 0;
        for (int j = 0; j < tmp.length(); j++)
        {
            if (tmp[j] != ' ')
            {
                A[i][num] = tmp[j] - '0';
                num++;
            }
            
        }
    }
    for (int i = 0; i < n; i++)
    {
        getline(cin, tmp);
        num = 0;
        for (int j = 0; j < tmp.length(); j++)
        {
            if (tmp[j] != ' ')
            {
                B[i][num] = tmp[j] - '0';
                num++;
            }
        }
    }
    bool canChange = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] != B[i][j])
            {
                canChange = IsVaild(j, i);
                if (!canChange)
                {
                    cout << -1;
                    return 0;
                }
                ReverseMatrix(j, i);
                count++;
            }
        }
    }
    cout << count;
    return 0;
}