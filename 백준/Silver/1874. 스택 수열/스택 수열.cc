#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int number = 1;
	int index = 0;
	stack<int> numbering;
	cin >> n;
	vector<int> buff(n);
	vector<int> temp;
	for (int i = 0; i <n; i++)
	{
		cin >> buff[i];
	}
	while (number <= n)
	{
		numbering.push(number);
		temp.emplace_back(1);
		number++;	
		while (numbering.top() == buff[index])
		{
			index++;
			temp.emplace_back(0);
			numbering.pop();
			if (numbering.empty())
			{
				break;
			}
		}
	}
	if (!numbering.empty())
	{
		if (numbering.top() != buff[index])
		{
			cout << "NO";
			return 0;
		}
		else
		{
			while (!numbering.empty())
			{
				if (numbering.top() != buff[index])
				{
					cout << "NO";
					return 0;
				}
				index++;
				temp.emplace_back(0);
				numbering.pop();
			}
		}
	}

	for(int i = 0; i<temp.size(); i++)
	{
		if (temp[i] == 1)
		{
			cout << "+" << "\n";
		}
		else
		{
			cout << "-" << "\n";
		}
	}
}