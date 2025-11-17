#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> scoville, int K) {
  	priority_queue<int, vector<int>, greater<int>> pq;
	int answer = 0;
	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}
	while (pq.top()<K)
	{
		int num1 = pq.top();
		pq.pop();
		if (pq.empty())
		{
			answer = -1;
			return answer;
		}
		int num2 = pq.top();
		pq.pop();
		int tmp = num1 + (num2 * 2);
		pq.push(tmp);
		answer++;
	}
    return answer;
}