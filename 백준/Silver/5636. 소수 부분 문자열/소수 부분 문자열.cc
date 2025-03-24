#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str = "";
    vector<bool> isPrime(100001, true);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 100000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    while (true)
    {
        cin >> str;    
        if (str == "0")
        {
            break;
        }
        int max_prime = 2;
        string tmp = "";
        int num = 0;
        
        for (int i = 0; i < str.length(); i++)
        {
            for (int j = i; j < str.length(); j++)
            {
                tmp += str[j];
                num = stoi(tmp);
                if (num >= 100000) break;

                if (isPrime[num] && max_prime < num)
                {
                    max_prime = num;
                }   
            }
            tmp = "";
        }
        cout << max_prime << '\n';
    }

    return 0;
}
