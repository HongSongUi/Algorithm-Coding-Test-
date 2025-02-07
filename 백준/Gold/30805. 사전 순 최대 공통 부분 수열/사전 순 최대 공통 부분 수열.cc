#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> temp;
    int p1 = 0, p2 = 0;

    while (p1 < n && p2 < m) {
        int maxValue = -1;
        int next_p1 = -1, next_p2 = -1;

        for (int i = p1; i < n; i++) {
            for (int j = p2; j < m; j++) {
                if (arr1[i] == arr2[j] && arr1[i] > maxValue) {
                    maxValue = arr1[i];
                    next_p1 = i;
                    next_p2 = j;
                }
            }
        }

        if (maxValue == -1) break; 

        temp.push_back(maxValue);
        p1 = next_p1 + 1;
        p2 = next_p2 + 1;
    }

    cout << temp.size() << '\n';
    for (int x : temp) {
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}