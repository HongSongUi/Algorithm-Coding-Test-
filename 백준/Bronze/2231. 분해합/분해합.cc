#include <iostream>
using namespace std;
int main()
{
	int n = 0;
	cin >> n;
	int start = n-(to_string(n).length() *9);
	for (int i = start; i <= n; i++)
	{
		int sum = i;
		int temp = i;
		while (temp != 0)
		{
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;
    return 0;
}