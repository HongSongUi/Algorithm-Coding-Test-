#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	int num = 0;
	priority_queue<int, vector<int>, greater<int>> buff;
	while (n > 0)
	{
		cin >> num;
		if (num == 0)
		{
			if (buff.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << buff.top() << "\n";
				buff.pop();
			}
		}
		else
		{
			buff.push(num);
		}
		n--;
	}
}