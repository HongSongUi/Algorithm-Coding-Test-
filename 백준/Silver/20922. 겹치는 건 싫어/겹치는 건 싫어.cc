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
    int count = 0;
    int right =0, left = 0;
    vector<int> tmp(100001, 0);
    while (right < n)
    {
        if (tmp[arr[right]]< k)
        {
            tmp[arr[right]] ++;
            right++;
        }
        else
        {
            tmp[arr[left]]--;
            left++;
        }
       
        answer = max(answer, right - left);
    }
    cout << answer;
}