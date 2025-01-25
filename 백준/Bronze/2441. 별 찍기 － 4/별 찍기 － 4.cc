#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j > 0; j--)
        {
            if (j <= i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}