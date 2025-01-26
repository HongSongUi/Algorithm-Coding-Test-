#include <bits/stdc++.h>
using namespace std;
#define X 1000000007

long long Calc(long long num, long long s)
{
    long long ret = 1;
    while (s > 0)
    {
        if (s % 2 == 1)
        {
            ret = ret * num % X;
        }
        num = num * num % X;
        s /= 2;
    }


    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m = 0;
    cin >> m;
    long long n, s;
    long long answer = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> n >> s;
        answer += (s * Calc(n, X - 2)) % X;
    }
    cout << answer % X;
    return 0;
}