#include <bits/stdc++.h>
using namespace std;

bool FindPrime(long long num)
{
    if (num <= 1)
    {
        return false;
    }
    if (num == 2)
    {
        return true;
    }
    if (num % 2 == 0)
    {
        return false;
    }
    for (long long i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    long long num = 0;
    while (n--)
    {
        cin >> num;
        while (true)
        {
            bool isPrime = FindPrime(num);
            if (isPrime)
            {
                cout << num << '\n';
                break;
            }
            else
            {
                num++;
            }
        }
    }
    return 0;
}