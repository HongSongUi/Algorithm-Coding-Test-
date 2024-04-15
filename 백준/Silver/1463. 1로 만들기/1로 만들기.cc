#include <bits/stdc++.h>
using namespace std;

int Find(int n , vector<int>& buff)
{
	if (n == 1)
	{
		return 0;
	}
	if (buff[n] != -1)
	{
		return buff[n];
	}

	int result = Find(n - 1, buff)+1;

	if (n % 3 == 0)
	{
		result = min(Find(n / 3, buff) + 1, result) ;
	}
	if (n % 2 == 0)
	{
		result = min(Find(n / 2, buff) + 1, result);
	}
	buff[n] = result;
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	vector<int> buff(1000001, -1);

	cout<< Find(n, buff);
}