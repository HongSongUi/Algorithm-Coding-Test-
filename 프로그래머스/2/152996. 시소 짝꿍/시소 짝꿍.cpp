#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<int, long long> cnt;
	sort(weights.begin(), weights.end());

	for (int i = 0; i < weights.size(); i++)
	{
		int tmp = weights[i];
		if (cnt.count(tmp))
		{
			answer += cnt[tmp];
		}

		if (tmp * 2 % 3 == 0)
		{
			int n = tmp * 2 / 3;
			if (cnt.count(n))
			{
				answer += cnt[n];
			}
		}
		if (tmp % 2 == 0)
		{
			int n = tmp / 2;
			if (cnt.count(n))
			{
				answer += cnt[n];
			}
		}
		if (tmp * 3 % 4 == 0)
		{
			int n = tmp * 3 / 4;
			if (cnt.count(n))
			{
				answer += cnt[n];
			}
		}

		cnt[tmp]++;
	}
    return answer;
}