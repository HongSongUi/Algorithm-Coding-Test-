#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int c = 0, r = 0;
	cin >> c >> r;
	vector<vector<int>> seat(r, vector<int>(c, 0));
	int max_seat = r * c;
	int num = 0;
	cin >> num;
	if (num > max_seat)
	{
		cout << 0;
		return 0;
	}
	int answer_x = 0;
	int answer_y = 0;
	int y_limit = r;
	int x_limit = c-1;
	int count = 1;
	int dir = -1;
	int tmp = 1;
	int p = 0;
	int q = r;
	bool find = false;
	while (true)
	{
		for (int i = 0; i < y_limit; i++)
		{
			q += dir;
			seat[q][p] = count;
			answer_y += tmp;
			if (count == num)
			{
				find = true;
				break;
			}
			
			count++;
			
		}
		if (find) break;
		y_limit--;
		dir *= -1;
		for (int j = 0; j < x_limit; j++)
		{
			p += dir;
			seat[q][p] = count;
			answer_x += tmp;
			if (count == num)
			{
				find = true;
	
				break;
			}
			count++;
		}
		x_limit--;
		tmp = -tmp;
		if (find) break;
	}
	cout << answer_x+1 << ' ' << answer_y;
	return 0;
}