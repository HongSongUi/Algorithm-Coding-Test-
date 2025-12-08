#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    	vector<int> vec(sequence.size() + 1, 0);
	for (int i = 1; i < vec.size(); i++)
	{
		vec[i] = vec[i - 1] + sequence[i - 1];
	}
	int left = 0;
	int right = 1;
	int p1 = 0;
	int p2 = 0;
	int l = 0;
	int min_len = INT_MAX;
	while (left <= right && right< vec.size())
	{
		int num = vec[right] - vec[left];
		if (num < k)
		{
			right++;
		}
		else
		{
			if (num == k)
			{
				l = right - left;
				if (l < min_len)
				{
					min_len = l;
					p1 = left;
					p2 = right-1;
				}
			}
			left++;
		}
		
		
	}
	answer.emplace_back(p1);
	answer.emplace_back(p2);
    return answer;
}