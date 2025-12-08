#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
	queue<int> vec;
	for (int i = 0; i < truck_weights.size(); i++)
	{
		vec.push(truck_weights[i]);
	}

	queue<pair<int, int>> trucks;
	queue<int> q;
	int cur_weight = 0;
	int tick = 0;

	while (q.size() < truck_weights.size())
	{
		tick++;
		if (!trucks.empty())
		{
			int t = trucks.front().second + bridge_length;
			if (tick >= t)
			{
				q.push(trucks.front().first);
				cur_weight -= trucks.front().first;
				trucks.pop();

			}
		}
		if (!vec.empty()  && cur_weight + vec.front() <= weight)
		{
			trucks.push(make_pair(vec.front(), tick));
			cur_weight +=vec.front();
			vec.pop();
		}
	}
	answer = tick;
    return answer;
}