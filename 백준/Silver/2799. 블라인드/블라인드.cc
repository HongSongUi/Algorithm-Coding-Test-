#include <bits/stdc++.h>
using namespace std;
vector<int> arr(5, 0);
vector<vector<char>> building;
vector<vector<bool>> visited;

void CheckType(int start_x, int start_y)
{
    int count = 0;
    int end_y = start_y + 5;
    int end_x = start_x + 5;
    for (int i = start_y; i < end_y; i++)
    {
        for (int j = start_x; j < end_x; j++)
        {
            visited[i][j] = true;
            if (building[i][j] == '*')
            {
                count++;
            }
        }

    }
    arr[count / 4]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m = 0, n = 0;
    cin >> m >> n;
    
    string s = "";
   
    int height = (5 * m) + 1;
    int width = (5 * n) + 1;
    building.resize(height, vector<char>(width));
    visited.resize(height, vector<bool>(width, false));
    
    for (int i = 0; i < height; i++)
    {
        cin >> s;
        for (int j = 0; j < width; j++) 
        {
            building[i][j] = s[j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if ((building[i][j] == '.' || building[i][j] == '*') && visited[i][j] == false)
            {
                CheckType(j, i);
            }
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] <<' ';
    }
    return 0; 
}