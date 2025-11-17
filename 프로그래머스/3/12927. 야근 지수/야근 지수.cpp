#include <bits/stdc++.h>
using namespace std;

long long solution(int n, vector<int> works) {
  
	long long answer = 0;
	priority_queue<int> pq;

	for (int i = 0; i < works.size(); i++)
	{
		pq.push(works[i]);
	}
	while (n--&& !pq.empty())
	{
		int tmp = pq.top();
		pq.pop();
		tmp--;
		if (tmp > 0)
		{
			pq.push(tmp);
		}
	}
	while (!pq.empty())
	{
		int num = pq.top();
		pq.pop();
		answer += pow(num, 2);
	}
    return answer;
}