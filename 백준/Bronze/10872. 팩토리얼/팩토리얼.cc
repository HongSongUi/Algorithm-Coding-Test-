#include <bits/stdc++.h>
using namespace std;

long long Factorial(int num)
{
    if (num <= 1) return 1;

    return num * Factorial(num - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0;
    cin >> n;
    cout << Factorial(n);
    return 0;
}