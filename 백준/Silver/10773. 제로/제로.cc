#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int count = 0;
	cin >> count;
	int num = 0;
	stack<int> buff;

	int result = 0;
	for (int i = 0; i < count; i++)
	{
		cin >> num;
		if (num != 0)
		{
			buff.push(num);
			result += num;
		}
		else if (num == 0)
		{
			result -= buff.top();
			buff.pop();
		}
	}
	cout << result;
}