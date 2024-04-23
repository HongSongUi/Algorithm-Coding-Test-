#include <bits/stdc++.h>
using namespace std;

void QuadTree(int left, int top, int right, int bottom, vector<vector<int>>& arr, int& b, int& w)
{
	int start = arr[top][left];
	bool div = false;
	for (int i = top; i < bottom; i++)
	{
		for (int j = left; j < right; j++)
		{
			if (start != arr[i][j])
			{
				div = true;
				break;
			}
		}
		if (div) break;
	}
	if (div == false)
	{
		if (start == 1)
		{
			b++;
		}
		else
		{
			w++;
		}
	}
	else
	{
		QuadTree(left, top, (left + right) / 2, (top+bottom) / 2, arr, b, w);
		QuadTree((left + right) /2, top, right, (top + bottom) / 2, arr, b, w);
		QuadTree(left, (top + bottom) /2, (left + right) /2, bottom, arr, b, w);
		QuadTree((left + right) / 2, (top + bottom) / 2, right , bottom , arr, b, w);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;
	int blue_count = 0;
	int white_count = 0;
	vector<vector<int>> arr(N,vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	QuadTree(0, 0, N, N, arr, blue_count, white_count);
	cout << white_count << "\n" << blue_count;
}