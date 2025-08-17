#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long dp[55];
long long countOnes(long long x) 
{
    if (x < 0) return 0;
    long long ans = x & 1; 
    for (int i = 54; i >= 1; i--) 
    {
        if (x & (1LL << i))
        {
            ans += dp[i - 1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    dp[0] = 1;
    for (int i = 1; i < 55; i++) 
    {
        dp[i] = dp[i - 1] * 2 + (1LL << i);
    }

    long long A, B;
    cin >> A >> B;
    cout << countOnes(B) - countOnes(A - 1);
    return 0;
}