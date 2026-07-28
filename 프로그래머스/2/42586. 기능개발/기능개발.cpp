#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   	vector<int> answer;
	queue<pair<int,int>> q;
	for (int i = 0; i < progresses.size(); i++)
	{
		q.push(make_pair(progresses[i],speeds[i]));
	}

	while (!q.empty())
	{
		int cnt = 0;
		int cur_progress = q.front().first;
		int cur_speed = q.front().second;

	    int diff = (100 - cur_progress + cur_speed - 1) / cur_speed;
		while (!q.empty())
		{
			if (q.front().first + (q.front().second * diff) >= 100)
			{
				q.pop();
				cnt++;
			}
			else
			{
				break;
			}
		}
		answer.emplace_back(cnt);
	}
    return answer;
}