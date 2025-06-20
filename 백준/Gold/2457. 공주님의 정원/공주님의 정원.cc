#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 0;
    cin >> n;
    vector<pair<int, int>> arr(n);
    int s_m = 0;
    int s_d = 0;
    int e_m = 0;
    int e_d = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s_m >> s_d >> e_m >> e_d;
        s_m *= 100;
        e_m *= 100;
        arr[i] = make_pair(s_m + s_d, e_m + e_d);
    }
    sort(arr.begin(), arr.end(), cmp);
    int curDay = 301;
    int count = 0;
    int idx = 0;
    int last = 0;
    bool isFind = false;
    while (curDay <= 1130)
    {
        isFind = false;
        for (int i = idx; i < n; i++)
        {
            int s = arr[i].first;
            if (s > curDay)
            {
                break;
            }
            else
            {
                isFind = true;
                idx = i+1;
                last = max(arr[i].second, last);
            }

        }
        if (!isFind)
        {
            count = 0;
            break;
        }
        count++;
        curDay = last;

    }
    cout << count;
    return 0;
}
