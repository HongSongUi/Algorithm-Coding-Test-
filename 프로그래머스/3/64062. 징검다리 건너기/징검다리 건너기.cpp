#include <bits/stdc++.h>

using namespace std;
bool IsValid(vector<int>& vec, int k, int num)
{
	int tmp = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] - num <= 0)
		{
			tmp++;
		}
		else
		{
			tmp = 0;
		}
		if (tmp >= k) return false;
	}
	return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

	int lo = 0;
	int hi = *max_element(stones.begin(), stones.end());

	while (lo < hi)
	{
		int mid = (lo + hi) / 2;
		if (IsValid(stones, k, mid))
		{
			lo = mid + 1;
		}
		else
		{
			hi = mid;
		}
	}
	answer = lo;
    return answer;
}