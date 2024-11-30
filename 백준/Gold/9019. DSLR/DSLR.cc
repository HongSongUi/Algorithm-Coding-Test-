#include <bits/stdc++.h>
using namespace std;

int LeftShift(int num) 
{
	int d1 = num / 1000;           
	int rest = num % 1000;         
	return rest * 10 + d1;         
}

int RightShift(int num) 
{
	int d4 = num % 10;             
	int rest = num / 10;           
	return d4 * 1000 + rest;       
}

void BFS(int temp,int target)
{
	vector<bool> visit(10000, false);
	queue<pair<int, string>> q;
	vector<string> order = { "D","S","L","R" };
	q.push(make_pair(temp, ""));
	visit[temp] = true;
	while (!q.empty())
	{
		int cur = q.front().first;
		string ord = q.front().second;
		q.pop();
		for (int i = 0; i < order.size(); i++)
		{
			int next = cur;
			string t = ord;
			if (order[i] == "D")
			{
				next *= 2;
				if (next > 9999)
				{
					next %= 10000;
				}
			}
			else if (order[i] == "S")
			{
				next -= 1;
				if (next < 0)
				{
					next = 9999;
				}
			}
			else if (order[i] == "L")
			{
				next = LeftShift(next);
			}
			else if (order[i] == "R")
			{
				next = RightShift(next);
			}
			t += order[i];
			if (next == target)
			{
				cout << t << "\n";
				return;
			}
			else
			{
				if (visit[next] == false)
				{
					visit[next] = true;
					
					q.push(make_pair(next, t));
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int count = 0;
	cin >> count;
	int temp = 0;
	int target = 0;
	while (count-- > 0)
	{
		cin >> temp >> target;
		BFS(temp, target);
	}
}