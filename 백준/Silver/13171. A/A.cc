#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long Calc(long long base, long long p)
{
    long long r = 1;
    base %= MOD;
    while (p > 0)
    {
        if (p % 2 == 1)
        {
            r = (r * base) % MOD;
        }
        base = (base * base) % MOD;
        p /= 2;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, x = 0;
    cin >> a >> x;

    cout << Calc(a, x);
    return 0;
}