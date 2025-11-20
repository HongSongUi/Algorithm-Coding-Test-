#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

 	stack<int> sub;
	queue<int> q;
	for (int i = 0; i < order.size(); i++)
	{
		q.push(i + 1);
	}
	
	int idx = 0;
	int box = order[0];
	while (q.front() != box)
	{
		int n = q.front();
		q.pop();
		sub.push(n);
	}
	while (true)
	{
		if (idx > order.size()-1)break;
		box = order[idx];
		if (q.empty() && box != sub.top()) break;
		if (!q.empty() && box == q.front())
		{
			answer++;
			idx++;
			q.pop();
		}
		else if (!sub.empty() &&box == sub.top())
		{
			answer++;
			idx++;
			sub.pop();
		}
		else
		{
			while (true)
			{
				if (q.empty()) break;
				if (q.front() == box) break;
				sub.push(q.front());
				q.pop();
			}
		}

	}
	

    return answer;
}