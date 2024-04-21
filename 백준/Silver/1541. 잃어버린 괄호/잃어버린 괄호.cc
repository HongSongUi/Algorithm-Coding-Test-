#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	string buff = "";
	cin >> buff;
	int num = 0;
	int sum = 0;
	string temp = "";
	bool plag = false;
	for (int i = 0; i < buff.length()+1; i++)
	{
		if (buff[i] >= '0' && buff[i] <= '9')
		{
			temp += buff[i];
		}
		else
		{	
			int num = stoi(temp);
			if (plag == false)
			{
				sum += num;
			}
			else
			{
				if (num > 0)
				{
					num *= -1;
				}
				sum += num;
			}
			if (buff[i] == '-')
			{
				plag = true;
			}
			temp = "";
		}
	}
	cout << sum;
}