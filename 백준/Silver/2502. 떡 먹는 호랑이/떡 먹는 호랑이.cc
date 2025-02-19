#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int day = 0, tt = 0;
    cin >> day >> tt;
    vector<int> a1;
    vector<int> a2;
    a1.emplace_back(1);
    a1.emplace_back(0);
    a2.emplace_back(0);
    a2.emplace_back(1);
    for (int i = 2; i < day; i++)
    {
        a1.emplace_back(a1[i - 1] + a1[i - 2]);
        a2.emplace_back(a2[i - 1] + a2[i - 2]);
    }
    int c1 = a1[day - 1];
    int c2 = a2[day - 1];
    for (int i = 1; i < tt; i++)
    {
        for (int j = i; j < tt; j++)
        {
            int num = (c1 * i) + (c2 * j);
            if (num > tt) break;
            else if (num == tt)
            {
                cout << i << '\n' << j;
                return 0;
            }
        }
    }
    return 0;
}