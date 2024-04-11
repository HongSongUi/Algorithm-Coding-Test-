#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	string temp = "";
	stack<int> buff;
	bool right = true;

	while (true)
	{
		getline(cin, temp);
		if (temp == ".")
		{
			break;
		}
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == '[')
			{
				buff.push(0);
			}
			else if (temp[i] == '(')
			{
				buff.push(1);
			}
			else if (temp[i] == ')')
			{
				if (buff.empty())
				{
					right = false;
					break;
				}
				else if (buff.top() != 1)
				{
					right = false;
					break;
				}
				else
				{
					buff.pop();
				}
			}
			else if (temp[i] == ']')
			{
				if (buff.empty())
				{
					right = false;
					break;
				}
				else if (buff.top() != 0)
				{
					right = false;
					break;
				}
				else
				{
					buff.pop();
				}
			}
		}
		if (buff.empty() && right == true)
		{
			cout << "yes" << "\n";
		}
		else if (buff.empty() && right == false)
		{
			cout << "no" << "\n";
		}
		else if(!buff.empty())
		{
			cout << "no" << "\n";
		}
		right = true;
	
		while (!buff.empty()) buff.pop();
	}
}