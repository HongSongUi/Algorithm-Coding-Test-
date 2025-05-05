#include <bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int money = 0;
	cin >> money;
	int j_money = money, s_money = money;
	int count1 = 0, count2 = 0;
	vector<int> graph(14);

	for (int i = 0; i < 14; i++)
	{
		cin >> graph[i];
	}
	for (int i = 0; i < 14; i++)
	{

		int buy = j_money / graph[i];
		count1 += buy;
		j_money -= buy * graph[i];

	}
	int up = 0, down = 0;
	for (int i = 1; i < 14; i++)
	{
		if (graph[i] > graph[i - 1])
		{
			up++;
			down = 0;
		}
		else if (graph[i] < graph[i - 1])
		{
			down++;
			up = 0;
		}
		if (up >= 3)
		{
			s_money += count2 * graph[i];
			count2 = 0;
		}
		else if (down >= 3)
		{
			int buy = s_money / graph[i];
			count2 += buy;
			s_money -= buy * graph[i];
		}
	}
	j_money = j_money + (graph[13] * count1);
	s_money = s_money + (graph[13] * count2);
	if (j_money > s_money) {
		cout << "BNP\n";
	}
	else if (j_money < s_money) {
		cout << "TIMING\n";
	}
	else {
		cout << "SAMESAME\n";
	}
	return 0;
}