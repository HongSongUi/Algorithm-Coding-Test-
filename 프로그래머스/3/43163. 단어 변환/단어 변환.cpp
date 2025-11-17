#include <bits/stdc++.h>

using namespace std;
int BFS(vector<string>& words, string begin, string target)
{
	vector<bool> visited(words.size(), false);
	queue<pair<string, int>> q;
	q.push(make_pair(begin, 0));
	int ret = 0;
	while (!q.empty())
	{
		string cur_word = q.front().first;
		int d = q.front().second;
		q.pop();
		if (cur_word == target)
		{
			ret = d;
			break;
		}
		int diff = 0;
		for (int i = 0; i < words.size(); i++)
		{
			string tmp = words[i];
			diff = 0;
			for (int j = 0; j < tmp.size(); j++)
			{
				if (tmp[j] != cur_word[j])
				{
					diff++;
				}
			}
			if (diff == 1&& !visited[i])
			{
				q.push(make_pair(tmp, d + 1));
				visited[i] = true;
			}
		}
	}
	return ret;
}
int solution(string begin, string target, vector<string> words) {
   	int answer = BFS(words, begin, target);

    return answer;
}