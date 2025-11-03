#include <bits/stdc++.h>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
	string buff = "";
	int num = 0;
	int cur_num = 0;
	while (true)
	{
		if (buff.length() > (t*m))
		{
			break;
		}
		
		num = cur_num;
		string s = "";
		if (num == 0)
		{
			buff = "0";
		}
		else
		{
			while (num != 0)
			{
				int tmp = num % n;
				if (tmp >= 10)
				{
					char ch = 'A' + tmp - 10;
					s = ch + s;
				}
				else
				{
					s = to_string(tmp) +s;
				}
				
				num /= n;
			}
		}
		buff += s;
		cur_num++;
	}
	p--;
	for (int i = 0; i < t; i++)
	{
		answer += buff[i * m + p];
	}

    return answer;
}