#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	cin >> t;
	string number = "";

	while (t--)
	{
		cin >> number;
		int len = number.length() -1;
		int index = -1;
		int target_index = 0;
		for (int i = len ; i > 0; i--)
		{
			int num = number[i] - '0';
			for (int j = i; j > 0; j--)
			{
				if (i == j) continue;
				if (num > (number[j] - '0'))
				{
					if (index < j)
					{
						index = j;
						target_index = i;
						break;
					}
				}
			}
		}
		if (index == -1)
		{
			cout << "BIGGEST" << '\n';
		}
		else
		{
			char ch = number[index];
			number[index] = number[target_index];
			number[target_index] = ch;
			sort(number.begin() + index + 1, number.end());
			cout << number << '\n';
		}
		
	}
	return 0;
}