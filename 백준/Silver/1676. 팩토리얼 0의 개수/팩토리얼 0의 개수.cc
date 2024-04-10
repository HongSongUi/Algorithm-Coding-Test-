#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n = 0;
	cin >> n;
	int temp = 0;
	while (n !=0)
	{
		temp = temp + (n / 5);
		n = n / 5;
	}
	cout << temp;	
}