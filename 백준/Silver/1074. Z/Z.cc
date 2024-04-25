#include <bits/stdc++.h>
using namespace std;
int N = 0;
int row = 0;
int col = 0;
void Search(int left, int top, int right, int bottom, int& depth,vector<vector<int>>& arr, int& count)
{
	
	if (!((col >= left && col < right) && (row >= top && row < bottom)))
	{	
		int num = pow(2, N- depth);
		count += num * num;
		return;
	}
	if (depth < N - 1)
	{
		
		int mid_x = (left + right) / 2;
		int mid_y = (top + bottom) / 2;
		int d = depth + 1;
		Search(left, top, mid_x, mid_y, d, arr, count);
		Search(mid_x, top, right, mid_y, d, arr,  count);
		Search(left, mid_y, mid_x, bottom, d, arr,  count);
		Search(mid_x, mid_y, right, bottom, d, arr, count);
	}
	else
	{
		
		for (int i = top; i < bottom; i++)
		{
			for (int j = left; j < right; j++)
			{
				count++;
				if (i == row && j == col)
				{
					cout << count - 1;
					return;
				}
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	int num = pow(2, N);
	vector<vector<int>>buff(N, vector<int>(N, 0));

	cin >> row >> col;
	int depth = 0;
	int count = 0;
	Search(0, 0, num, num, depth, buff, count);
}