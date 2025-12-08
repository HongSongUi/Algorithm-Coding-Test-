#include <bits/stdc++.h>
using namespace std;

bool IsValid(int l)
{
	return l > 0;
}

vector<int> solution(int n) {
    vector<int> answer;
    int s = 1;
	for (int i = 2; i <= n; i++)
	{
		s += i;
	}
	answer.resize(s);
	int idx = 0;
	int dir = 0;

	int limit = n;
	int num = 1;
	int p = 0;
	int tmp = 0;
	while (true)
	{
		if (dir == 0)
		{
			for (int i = 0; i < limit; i++)
			{
				p += tmp;
				answer[p] = num;
			
				tmp++;
				num++;
			}

		}
		else if (dir == 1)
		{
			for (int i = 0; i < limit; i++)
			{
				p++;
				answer[p] = num;
				num++;
			}
		}
		else if (dir == 2)
		{
			for (int i = 0; i < limit; i++)
			{
				p -= tmp;
				answer[p] = num;
				num++;
				tmp--;
			}

		}

		dir++;
		dir %= 3;
		limit--;
		if (limit<=0)break;
	}
	
    return answer;
}