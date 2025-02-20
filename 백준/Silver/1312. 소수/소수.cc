#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b;
    int n;
    cin >> a >> b >> n;

    a %= b; 

    for (int i = 0; i < n; i++) {
        a *= 10; 
        if (i == n - 1) {
            cout << a / b << '\n';  
            break;
        }
        a %= b;  
    }

    return 0;
}