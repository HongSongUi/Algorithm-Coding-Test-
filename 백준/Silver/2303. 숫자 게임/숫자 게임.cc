#include <bits/stdc++.h>
using namespace std;

void Combination(vector<int>& tmp , vector<int>& arr,int& max_num,int start)
{
	if (tmp.size() == 3)
	{
		int num = 0;
		for (int i = 0; i < 3; i++)
		{
			num += tmp[i];
		}
		num %= 10;
		if (num > max_num)
		{
			max_num = num;
		}
		return;
	}
	for (int i = start; i < 5; i++)
	{
		tmp.emplace_back(arr[i]);
		Combination(tmp, arr, max_num, i + 1);
		tmp.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 0;
	cin >> n;
	
	int winner = 0;
	int num = 0;
	int count = 1;
	while (count <= n)
	{
		vector<int> arr(5);
		vector<int> tmp;
		for (int i = 0; i < arr.size(); i++)
		{
			cin >> arr[i];
		}
		int max_num = 0;
		Combination(tmp, arr, max_num, 0);
		if (max_num >= num)
		{
			winner = count;
			num = max_num;
		}
		count++;
	}
	cout << winner;
	return 0;
}