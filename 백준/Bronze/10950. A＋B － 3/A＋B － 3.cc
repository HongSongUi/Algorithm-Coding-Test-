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

	int a, b;
	while (n--)
	{
		cin >> a >> b;
		cout << a + b << '\n';
	}
	return 0;
}
