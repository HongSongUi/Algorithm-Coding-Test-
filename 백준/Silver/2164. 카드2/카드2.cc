#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	bool state = true;
	queue<int> cards;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cards.push(i + 1);
	}
	while (cards.size() > 1)
	{	
		cards.pop();
		cards.push(cards.front());
		cards.pop();
	}
	cout << cards.front();
}