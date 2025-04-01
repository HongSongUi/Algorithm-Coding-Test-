#include <bits/stdc++.h>
using namespace std;

bool IsVaild(vector<pair<int,int>>&arr)
{
    vector<long long> lengths;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            int dx = arr[i].first - arr[j].first;
            int dy = arr[i].second - arr[j].second;
            lengths.emplace_back(dx * dx + dy * dy);
        }
    }
    sort(lengths.begin(), lengths.end());

    return lengths[0] == lengths[1] && lengths[1] == lengths[2] && lengths[2] == lengths[3]
        && lengths[4] == lengths[5];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;
    cin >> t;

    while (t--)
    {
        vector<pair<int, int>> arr;
        int x, y;
        for (int i = 0; i < 4; i++)
        {
            cin >> x >> y;
            arr.emplace_back(make_pair(x, y));
        }
        if (IsVaild(arr))
        {
            cout << 1 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    return 0;
}