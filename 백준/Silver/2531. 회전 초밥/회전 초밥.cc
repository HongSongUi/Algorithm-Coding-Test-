#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, d = 0, k = 0, c = 0;
    cin >> n >> d >> k >> c;
    vector<int> arr(n);
    vector<int> buff(d + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = 0;
    int limit = left + k;
    int right = 0;
    int answer = 0;
    int tmp = 0;
    while (left<n)
    {
        while (right < limit)
        {
            buff[arr[right%n]]++;
            if (buff[arr[right % n]] == 1) tmp++;
            right++;
        }
        if (buff[c] == 0)
        {
            answer = max(answer, tmp+1);
        }
        else
        {
            answer = max(answer, tmp);
        }
        buff[arr[left]]--;
        if (buff[arr[left]] == 0) tmp--;

        left++;
        limit = left + k;
    }
    cout << answer;
    return 0;
}