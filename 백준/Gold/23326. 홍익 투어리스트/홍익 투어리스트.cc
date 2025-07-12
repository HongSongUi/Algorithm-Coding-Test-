#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
 
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    set<int> spot;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            spot.insert(i);
        }
    }
    int cur = 0;
    int tmp = 0;
    int num = 0;
    while (q--)
    {
        cin >> tmp;
        if (tmp == 1)
        {
            cin >> num;
            if (arr[num - 1] == 1)
            {
                spot.erase(spot.find(num - 1));
                arr[num - 1] = 0;
            }
            else
            {
                arr[num - 1] = 1;
                spot.insert(num - 1);
            }
        }
        else if (tmp == 2)
        {
            cin >> num;
            cur += num;
            cur %= n;
        }
        else if (tmp == 3)
        {
            if (spot.empty())
            {
                cout << -1 << '\n';
                continue;
            }
            auto iter = spot.lower_bound(cur); 
            int dist = 0;
            if (iter == spot.end())
            {
                int idx = *spot.begin();
                dist = (idx - cur + n) % n;
            }
            else
            {
                int idx = *iter;
                dist = idx - cur;
            }
            
            cout << dist << '\n';
        }
    }
    return 0;
}