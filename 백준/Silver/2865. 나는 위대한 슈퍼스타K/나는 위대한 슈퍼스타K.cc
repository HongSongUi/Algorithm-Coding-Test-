#include <bits/stdc++.h>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0, k = 0;
    cin >> n >> m >> k;

    vector<double> arr(n + 1 ,-1);
    int num = 0;
    double ability = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> num >> ability;
            
            if (arr[num] < ability)
            {
                arr[num] = ability;
            }
        }
    }
    sort(arr.begin(), arr.end(), greater<double>());
    double answer = 0;
    for (int i = 0; i < k; i++)
    {
        answer += arr[i];
    }
    cout << fixed;
    cout.precision(1);
    cout << answer;
    return 0;
}