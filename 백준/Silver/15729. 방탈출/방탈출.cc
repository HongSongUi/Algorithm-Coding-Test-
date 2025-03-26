#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> light(n, 0);
    vector<int> arr(n, 0);
    int point = n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1 && i < point)
        {
            point = i;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != light[i])
        {
            answer++;
            for (int j = i; (j < i + 3 && j < n); j++)
            {
                light[j] = 1 - light[j];
            }
        }
    } 
    cout << answer;
   
    return 0;
}
