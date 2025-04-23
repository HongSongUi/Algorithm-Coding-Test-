#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u = 0, n = 0;
    cin >> u >> n;
    vector<vector<string>> arr(u + 1);
    
    string name = "";
    int price = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> price;
        arr[price].emplace_back(name);
    }
    int min_count = INT_MAX;
    for (int i = 0; i <= u; i++)
    {
        if (arr[i].size() == 0) continue;
        if (arr[i].size() < min_count)
        {
            min_count = arr[i].size();
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].size() == min_count)
        {
            cout << arr[i][0] << ' ' << i;
            break;
        }
    }

    return 0;
}