#include <bits/stdc++.h>
using namespace std;

int n = 0;
string start, target;
vector<vector<int>> dp;
int DP(int pos, int rot)
{
    if (pos == n)
    {
        return 0;
    }
    if (dp[pos][rot] != -1)
    {
        return dp[pos][rot];
    }
    int curNum = ((start[pos] - '0') + rot) % 10;
    int targetNum = target[pos] - '0';
    
    int left = (targetNum - curNum  + 10) % 10;
    int right = (10 - left) % 10;
    
    dp[pos][rot] = min(left+ DP(pos + 1, (rot + left) % 10), right + DP(pos + 1, rot));
    return dp[pos][rot];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    cin >> start >> target;
    dp.resize(n, vector<int>(10, -1));
    
    cout << DP(0, 0);
    return 0;
}
