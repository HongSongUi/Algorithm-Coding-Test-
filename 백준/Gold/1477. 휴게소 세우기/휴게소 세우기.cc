#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, l = 0;
    cin >> n >> m >> l;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    arr.emplace_back(0);
    arr.emplace_back(l);
    sort(arr.begin(), arr.end());
    int left = 1;
    int right = l;
    int answer = 0;
    int tmp = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 1; i < arr.size(); i++)
        {
            int len = arr[i] - arr[i - 1];
            tmp = len / mid;
            if (tmp != 0)
            {
                if (len % mid == 0) tmp--;

                count += tmp;
            }
        }
     
        if (count > m)
        {
            left = mid + 1;
        }
        else
        {
            answer = mid;
            right = mid - 1;
        }
    }
    cout << answer;
    return 0;
}