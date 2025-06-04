#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> arr(n);
    vector<int> buff(100001,0);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int right = 0;
    long long answer = 0;
    while (left<n)
    {
        while (right < n && buff[arr[right]] == 0)
        {
            buff[arr[right]]++;
            right++;
        }
        answer += (right - left);
        buff[arr[left]]--;
        left++;
    }
    cout << answer;
    return 0;
}