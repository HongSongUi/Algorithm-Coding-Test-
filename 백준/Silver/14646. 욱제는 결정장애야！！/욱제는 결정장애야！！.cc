#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n = 0;
	cin >> n;
	int num = 0;
	vector<int> menu(n + 1, 0);
	int tmp = 0;
	int maxVal = -1;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> num;
		if (menu[num] == 0)
		{
			menu[num]++;
			tmp++;
		}
		else if (menu[num] >= 1)
		{
			tmp--;
		}
		if (tmp > maxVal)
		{
			maxVal = tmp;
		}
	}
	cout << maxVal;
	return 0;
}