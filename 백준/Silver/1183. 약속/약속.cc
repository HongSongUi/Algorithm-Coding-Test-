#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    
    vector<int> temp(n);
    int pTime = 0;
    int aTime = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> aTime >> pTime;
        temp[i] = (aTime - pTime);
    }
    sort(temp.begin(), temp.end());
    if (n % 2 == 1) cout << 1;
    else cout << temp[n / 2] - temp[n / 2 - 1] + 1;
    return 0;
}