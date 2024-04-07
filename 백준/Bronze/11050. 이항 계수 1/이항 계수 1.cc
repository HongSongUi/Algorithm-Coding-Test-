#include <iostream>
using namespace std;

int Factorial(int num)
{
	if (num == 1 || num == 0)
	{
		return 1;
	}
    else
    {
        return num * Factorial(num - 1);
    }
}

int main()
{
	int n, k = 0;
	cin >> n >> k;
	int Kfac = Factorial(k);
	int Nfac = Factorial(n);
	int temp = Factorial(n-k);
	int result = Nfac / (Kfac * temp);
	cout << result;
}