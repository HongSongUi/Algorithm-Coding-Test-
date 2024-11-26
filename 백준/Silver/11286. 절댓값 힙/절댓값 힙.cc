#include <bits/stdc++.h>
using namespace std;

struct cmp
{
	bool operator() (int a, int b)
	{
		if (abs(a) == abs(b)) 
		{
			
			return a > b;
		}
		
		return abs(a) > abs(b);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int count = 0;
	int num = 0;
	cin >> count;
	priority_queue<int, vector<int>, cmp> q;
	while (count > 0)
	{
		cin >> num;
		if (num != 0)
		{
			q.push(num);
		}
		else
		{
			if (q.size() == 0)
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << q.top() << '\n';
				q.pop();
			}
		}
		count--;
	}
}
