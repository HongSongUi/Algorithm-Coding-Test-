#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	int number = 666;
	int result = 0;
	int count = 1;
	cin >> n;
	string buff = "";
	while (count < n)
	{
		number++;
		buff = to_string(number);
		if (buff.find("666") != string::npos)
		{
			count++;
		}
	}
	cout << number;
}