#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

	queue<int> q1;
	queue<int> q2;
	
	long long s1 = 0;
	long long s2 = 0;
	for (int i = 0; i < queue1.size(); i++)
	{
		q1.push(queue1[i]);
		s1 += queue1[i];
		q2.push(queue2[i]);
		s2 += queue2[i];
	}
	int limit = queue1.size() * 4;
	long long half = (s1 + s2) / 2;
	long long num = 0;
	while (true)
	{
		if (s1 == half && s2 == half)
		{
			break;
		}
		if (answer > limit)
		{
			answer = -1;
			break;
		}
		if (s1 > s2)
		{
			num = q1.front();
			q1.pop();
			q2.push(num);
			s1 -= num;
			s2 += num;
		}
		else
		{
			num = q2.front();
			q2.pop();
			q1.push(num);
			s1 += num;
			s2 -= num;
		}
		answer++;
	}
    return answer;
}