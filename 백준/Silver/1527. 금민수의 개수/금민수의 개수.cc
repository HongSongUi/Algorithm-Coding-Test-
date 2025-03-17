#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b = 0;
	cin >> a >> b;

	int answer = 0;
	bool isMinsu = true;
	int num = 0;
	int tmp = 0;
	for (int i = a; i <= b; i++)
	{
		isMinsu = true;
		num = i;
		while (num > 0)
		{
			tmp = num % 10;
			if (tmp != 4 && tmp != 7)
			{
				isMinsu = false;
				break;
			}
			num /= 10;
		}
		if (isMinsu)
		{
			answer++;
		}
	}
	cout << answer;
	return 0;
}