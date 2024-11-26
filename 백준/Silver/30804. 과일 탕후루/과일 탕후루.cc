#include <bits/stdc++.h>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n = 0;
	int fruit = 0;

	cin >> n;
	vector<int> tang(n);
	map<int, int> temp;
	for (int i = 0; i < n; i++)
	{
		cin >> tang[i];
	}
	int front = 0;
	int back = 0;
	int max_count = 0;
	int fruit_count = 0;
	while (back < n) {

		temp[tang[back]]++;
		while (temp.size() > 2)
		{
			temp[tang[front]]--; 
			if (temp[tang[front]] == 0) 
			{
				temp.erase(tang[front]); 
			}
			front++;
		}
		max_count = max(max_count, back - front + 1);

		back++;
	}
	cout << max_count;
}
