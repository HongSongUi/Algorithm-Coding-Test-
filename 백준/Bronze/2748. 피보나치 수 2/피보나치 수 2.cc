#include <bits/stdc++.h>
using namespace std;

vector<long long> dp;
long long Fibonacci(int n)
{
    if (n <= 1)
    {
        dp[n] = n;
        return dp[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
    return dp[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    dp.resize(n +1, -1);
    cout << Fibonacci(n);

    return 0;
}