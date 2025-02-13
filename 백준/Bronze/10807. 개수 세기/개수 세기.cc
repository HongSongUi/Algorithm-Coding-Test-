#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;
    map<int, int> temp;
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        temp[num]++;
    }
    int k = 0;
    cin >> k;
    if (temp.find(k) == temp.end())
    {
        cout << 0;
    }
    else
    {
        cout << temp[k];
    }
    return 0;
}