#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    	multiset<int> q;
	
	for (int i = 0; i < operations.size(); i++)
	{
		string str = operations[i];
		if (str[0] == 'I')
		{
			string tmp = "";
			for (int j = 2; j < str.length(); j++)
			{
				tmp += str[j];
			}
			q.insert(stoi(tmp));
		}
		else if (str[0] == 'D')
		{
			if (q.empty()) continue;

			if (str[2] == '-')
			{
				q.erase(q.begin());
			}
			else
			{
				q.erase(--q.end());
			}

		}
	}
	if (q.empty())
	{
		answer.emplace_back(0);
		answer.emplace_back(0);
	}
	else
	{
		answer.emplace_back(*(--q.end()));
		answer.emplace_back(*q.begin());
	}

    return answer;
}