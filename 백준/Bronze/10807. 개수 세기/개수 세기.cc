#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	map<int, int> tmp;

	int num = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		tmp[num]++;
	}
	cin >> num;
	cout << tmp[num];
	return 0;
}
