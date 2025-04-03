#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k = 0;
    cin >> n >> k;
    vector<int> arr(n);
    int a, b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[i] = b - a;
    }
    sort(arr.begin(), arr.end());
    int answer = (arr[k - 1] <= 0) ? 0 : arr[k - 1];
    cout << answer;
    return 0;
}