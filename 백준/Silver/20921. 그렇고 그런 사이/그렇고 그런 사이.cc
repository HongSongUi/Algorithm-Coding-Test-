#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, k = 0;
    cin >> n >> k;
    vector<bool> arr(n + 1, false);
    vector<int> result;
    for(int i = n; i>0; i--)
    {
        int num = i-1;
        if (k - num >= 0)
        {
            arr[i] = true;
            result.emplace_back(i);
            k -= num;
        }
    }
    for (int i = 1; i < arr.size(); i++)
    {
        if (!arr[i])
        {
            result.emplace_back(i);
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << ' ';
    }
    return 0;
}