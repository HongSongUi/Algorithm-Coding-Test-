#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int s = 0;
int degree = 0;

void Rotate(int dir)
{
	vector<vector<int>>temp = arr;
	int num = s / 2;
	int tmp = s-1;
	for (int i = 0; i < s; i++)
	{
		if (dir > 0)
		{
			temp[i][num] = arr[i][i];
			temp[i][tmp] = arr[i][num];
			temp[num][i] = arr[tmp][i];
			temp[i][i] = arr[num][i];
		}
		else
		{
			temp[num][i] = arr[i][i];
			temp[i][i] = arr[i][num];
			temp[i][num] = arr[i][tmp];
			temp[tmp][i] = arr[num][i];
		}
		tmp--;
	}
	arr = temp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 0;
	cin >> t;

	while (t--)
	{
		cin >> s >> degree;
		
		int dir = 1;
		if (degree < 0)
		{
			dir = -1;
			degree *= -1;
		}
		degree /= 45;
        arr.clear();
		arr.resize(s, vector<int>(s));
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s; j++)
			{
				cin >> arr[i][j];
			}
		}
		while (degree--)
		{
			Rotate(dir);
		}
		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < s; j++)
			{
				cout << arr[i][j]<<" ";
			}
			cout << '\n';
		}
	}
	return 0;
}