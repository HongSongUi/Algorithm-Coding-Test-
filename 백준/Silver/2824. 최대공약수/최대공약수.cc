#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
vector<int> primes;
vector<bool> isPrime(40001, true);

void FindPrime()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 40000; i++)
    {
        if (isPrime[i])
        {
            primes.emplace_back(i);
            for (int j = i * 2; j <= 40000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}
void factorize(int n, map<int,int>& tmp)
{
    for (int i = 0; i < primes.size(); i++)
    {
        int num = primes[i];
        if (num * num > n) break;
        while (n % num == 0)
        {
            tmp[num]++;
            n /= num;
        }
    }
    if (n > 1) tmp[n]++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    FindPrime();
    int n = 0, m = 0;

    cin >> n;
    int num = 0;
    map<int, int> factorA;
    map<int, int> factorb;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        factorize(num, factorA);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> num;
        factorize(num, factorb);
    }
    long long answer = 1;
    bool isLarge = false;
    for (auto data : factorA)
    {
        if (factorb.find(data.first) == factorb.end()) continue;
        int p = min(data.second, factorb[data.first]);
        while (p--)
        {
            answer *= data.first;
            if (answer >= INF)
            {
                isLarge = true;
                answer %= INF;
            }
        }
    }
    if (isLarge) {
        cout << setw(9) << setfill('0') << answer << '\n';
    }
    else {
        cout << answer << '\n';
    }
    return 0;
}