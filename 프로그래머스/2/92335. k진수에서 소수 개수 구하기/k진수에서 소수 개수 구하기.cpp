#include <bits/stdc++.h>

using namespace std;

bool isPrimeCheck(long long x) 
{
	if (x < 2) return false;
	for (long long i = 2; i * i <= x; i++) 
	{
		if (x % i == 0) return false;
	}
	return true;
}


int solution(int n, int k) {
	vector<bool> isPrime(1000001, true);
	isPrime[0] = false;
	isPrime[1] = false;
	for (int i = 2; (long long)i*i < 1000001; i++)
	{
		if (isPrime[i])
		{
			for (int j = 2; (long long)i * j < 1000001; j++)
			{
				isPrime[i * j] = false;
			}
		}
	}
	long long answer = 0;
	string tmp = "";
	while (n > 0)
	{
		tmp += to_string(n % k);
		n /= k;
	}
	reverse(tmp.begin(), tmp.end());
	string str = "";
	for (long long i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] != '0')
		{
			str += tmp[i];
		}
		else
		{
			if (!str.empty())
			{
				long long num = stoll(str);
				if (num < 1000001) 
				{
					if (isPrime[num]) answer++;
				}

				else 
				{
					if (isPrimeCheck(num)) answer++;
				}
			}
			str = "";
		}
	}
	if (!str.empty())
	{
		long long num = stoll(str);
		if (num < 1000001)
		{
			if (isPrime[num]) answer++;
		}
		else
		{
			if (isPrimeCheck(num)) answer++;
		}
	}
    return answer;
}