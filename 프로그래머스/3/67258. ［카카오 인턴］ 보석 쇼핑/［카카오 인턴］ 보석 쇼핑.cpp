#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gems_set;
	map<string, int> gems_cnt;
	for (int i = 0; i < gems.size(); i++)
	{
		gems_set.insert(gems[i]);
	}
	int left = 0;
	int right = 0;
	int min_length = INT_MAX;

	int num1 = 0;
	int num2 = 0;
	while (right < gems.size())
	{
		gems_cnt[gems[right]]++;
		while (gems_cnt.size() == gems_set.size())
		{
			int cur_length = right - left + 1;
			if (cur_length < min_length)
			{
				min_length = cur_length;
				num1 = left+1;
				num2 = right+1;
			}
			gems_cnt[gems[left]]--;
			if (gems_cnt[gems[left]] <= 0) gems_cnt.erase(gems[left]);

			left++;
		}
		right++;
	}
	
	answer.emplace_back(num1 );
	answer.emplace_back(num2 );
    return answer;
}