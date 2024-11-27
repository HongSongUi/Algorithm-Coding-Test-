#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int count = 0;
	string AC = "";
	int num = 0;
	cin >> count;
	string input = "";
	string temp = "";
	deque<string> dq;
	string answer = "[";
	bool rev = false;
	bool flag = false;
	while (count > 0)
	{
		cin >> AC;
		cin >> num;
		cin >> input;
		input = input.substr(1, input.size() - 2);
		stringstream ss(input);
		string temp;
		while (getline(ss, temp, ',')) 
		{
			dq.push_back(temp);
		}
		for (int i = 0; i < AC.length(); i++)
		{
			if (AC[i] == 'R')
			{
				rev = !rev;
			}
			if (AC[i] == 'D')
			{
				if (dq.size() == 0)
				{
					flag = true;
					cout << "error" << '\n';
					break;
				}
				else
				{
					if (rev)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
			}
		}
		if (!flag)
		{
			while (dq.size() != 0)
			{
				if (rev)
				{
					answer += dq.back();
					answer += ',';
					dq.pop_back();
				}
				else
				{
					answer += dq.front();
					answer += ',';
					dq.pop_front();
				}
			}
			if (answer.length() > 1)
			{
				answer[answer.length() - 1] = ']';
			}
			else
			{
				answer += ']';
			}
			cout << answer << '\n';
		}
		count--;
		answer = "[";
		rev = false;
		flag = false;
	}
}
