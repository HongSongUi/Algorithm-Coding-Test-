#include <bits/stdc++.h>
using namespace std;
#define INF  10000000
vector<bool> arr(20000001, false);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    int card = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> card;
        card += INF;
        arr[card] = true;
    }
    int m = 0;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> card;
        card += INF;
        cout << arr[card] << ' ';
    }
}