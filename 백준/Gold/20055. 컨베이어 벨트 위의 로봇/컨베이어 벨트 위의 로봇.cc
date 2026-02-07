#include <bits/stdc++.h>

using namespace std;
vector<pair<int,bool>> vec;
int n = 0;
int k = 0;
void MoveBelt()
{
	int limit = n * 2;
	vector<pair<int, bool>> tmp = vec;
	for (int i = 1; i < limit; i++)
	{	
		vec[i] = tmp[i - 1];
	}
	vec[0] = tmp[limit - 1];
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	vec.resize(2 * n);
	
	
	for (int i = 0; i < 2*n; i++)
	{
		cin >> vec[i].first;
	}
	int answer = 0;
	int cnt = 0;
	int r_cnt = 0;
	while (cnt < k)
	{
		MoveBelt();
		if (vec[n - 1].second == true)
		{
			vec[n - 1].second = false;
            r_cnt--;
		}
		if (r_cnt > 0)
		{
			for (int i = n - 2; i >= 0; i--)
			{
				int next_idx = i + 1;
				if (vec[i].second == false) continue;
				if (vec[next_idx].first > 0 && !vec[next_idx].second)
				{
					vec[next_idx].first--;
					if (vec[next_idx].first == 0)
					{
						cnt++;
					}
					if (next_idx == n - 1)
					{
						r_cnt--;
						vec[next_idx].second = false;
					}
					else
					{
						vec[next_idx].second = true;
					}
					vec[i].second = false;
				}
			}
		}
		if (vec[0].first > 0)
		{
			vec[0].first--;
			vec[0].second = true;
			r_cnt++;
			if (vec[0].first == 0) cnt++;
		}
		answer++;
	}
	cout << answer;
	return 0;
}
