#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int answer = 0;
    int left = 0;
    int right = 0;
    int odd_count = 0;
    int tmp = 0;
    while (left < n)
    {
        while (right < n && odd_count <= k)
        {
            if (arr[right] % 2 != 0) odd_count++;
            right++;
        }
        tmp = (right - left) - odd_count;
        answer = max(answer, tmp);
        if (arr[left] % 2 != 0) odd_count--;
        left++;
    }
    cout << answer;
    return 0;
}