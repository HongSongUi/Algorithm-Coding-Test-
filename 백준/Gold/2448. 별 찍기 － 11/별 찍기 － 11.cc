#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> temp;

void Star(int x, int y, int n)
{
	if (n == 3)
	{
		temp[y][x] = '*';
		temp[y + 1][x + 1] = '*';
		temp[y + 1][x - 1] = '*';
		for (int i = x - 2; i <= x + 2; i++)
		{
			temp[y + 2][i] = '*';
		}
	}
	else
	{
		Star(x, y, n / 2);
		Star(x + n / 2, y + n / 2, n / 2);
		Star(x - n / 2, y + n / 2, n / 2);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y = 0;
	cin >> y;
	int x = y * 2;
	temp.resize(y, vector<char>(x - 1, ' '));

	Star(y - 1, 0, y);

	for (int i = 0; i < temp.size(); i++)
	{
		for (int j = 0; j < temp[0].size(); j++)
		{
			cout << temp[i][j];
		}
		cout << '\n';
	}
	return 0;
}