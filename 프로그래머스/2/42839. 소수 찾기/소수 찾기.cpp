#include <bits/stdc++.h>

using namespace std;
vector<bool> isPrime;
vector<bool> visited;
set<int> primes;


void FindPrime(int cnt,  string num,  string s,int limit)
{
	if (cnt == limit)
	{
		int n = stoi(s);
		if (isPrime[n]) primes.insert(n);

		return;
	}
	for (int i = 0; i < num.length(); i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			FindPrime(cnt + 1, num, s + num[i],limit);
			visited[i] = false;
		}
	}
}
int solution(string numbers) {
    int answer = 0;
    	
    int limit = pow(10, numbers.length());
	isPrime.resize(limit, true);


	visited.resize(numbers.length(), false);
	isPrime[0] = false;
	isPrime[1] = false;

	for (int i = 2; i * i < limit; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*i; j < limit; j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
	
	
	for (int i = 1; i <= numbers.length(); i++)
	{
		string s = "";
		FindPrime(0, numbers, s, i);
	}
	answer = primes.size();
    return answer;
}